import typing
import psycopg2
from .._credentials import *

def process(x: str) -> typing.Union[str, None]:
    """[summary]

    Args:
        x (str): [description]

    Returns:
        typing.Union[str, None]: [description]
    """
    return x if int(x) else None

class Connector:
    def __init__(self):
        """[summary]
        """
        self.conn = psycopg2.connect(user=user,
                                     password=password,
                                     host=host,
                                     database=database,
                                     options=options)
        self.cur = self.conn.cursor()
    def bulk_upload(self):
        """[summary]
        """
        with open("/tmp/.users", "r") as fout:
            self.cur.copy_expert(\
                '''
                COPY
                    users(
                        user_name,
                        sex,
                        gender,
                        education_level,
                        dob,
                        created
                    )
                FROM
                    STDIN
                (
                    FORMAT CSV,
                    NULL '\\N'
                )
                ''',
                fout
            )
            self.conn.commit()
        with open("/tmp/.posts") as fout:
            self.cur.copy_expert(\
                '''
                COPY
                    posts(
                        user_id,
                        textual_content,
                        time_posted
                    )
                FROM
                    STDIN
                (
                    FORMAT CSV,
                    NULL '\\N'
                )
                ''',
                fout
            )
            self.conn.commit()
        with open("/tmp/.post_media") as fout:
            self.cur.copy_expert(\
                '''
                COPY
                    post_media(
                        post_id,
                        url
                    )
                FROM
                    STDIN
                (
                    FORMAT CSV,
                    NULL '\\N'
                )
                ''',
                fout
            )
            self.conn.commit()
        with open("/tmp/.post_comments") as fout:
            self.cur.copy_expert(\
                '''
                COPY
                    post_comments(
                        post_id,
                        user_id,
                        textual_content,
                        time_commented
                    )
                FROM
                    STDIN
                (
                    FORMAT CSV,
                    NULL '\\N'
                )
                ''',
                fout
            )
            self.conn.commit()
        with open("/tmp/.post_comment_media") as fout:
            self.cur.copy_expert(\
                '''
                COPY
                    post_comment_media(
                        post_comment_id,
                        url
                    )
                FROM
                    STDIN
                (
                    FORMAT CSV,
                    NULL '\\N'
                )
                ''',
                fout
            )
            self.conn.commit()
        with open("/tmp/.followings") as fout:
            self.cur.copy_expert(\
                '''
                COPY
                    followings(
                        from_id,
                        to_id,
                        time_initiated
                    )
                FROM
                    STDIN
                (
                    FORMAT CSV,
                    NULL '\\N'
                )
                ''',
                fout
            )
            self.conn.commit()
        with open("/tmp/.post_likes") as fout:
            self.cur.copy_expert(\
                '''
                COPY
                    post_likes(
                        post_id,
                        user_id,
                        time_liked
                    )
                FROM
                    STDIN
                (
                    FORMAT CSV,
                    NULL '\\N'
                )
                ''',
                fout
            )
            self.conn.commit()
    def remove_user(self, id: str):
        self.cur.execute("DELETE FROM users WHERE id = %s", vars=(id,))
        self.conn.commit()
    def update_user(self,
                    id: str,
                    user_name: str,
                    sex: str,
                    gender: str,
                    education_level: str,
                    dob: str):
        self.cur.execute(\
            '''
            UPDATE
                users
            SET
                user_name = %s,
                sex = %s,
                gender = %s,
                education_level = %s,
                dob = %s
            WHERE
                id = %s
            ''',
            (
                user_name,
                process(sex),
                process(gender),
                process(education_level),
                dob,
                id
            )
        )
        self.conn.commit()
    def remove_post(self,
                    id: str):
        self.cur.execute("DELETE FROM posts WHERE id = %s", vars=(id,))
        self.conn.commit()
    def close(self):
        if (self.cur):
            self.cur.close()
        if (self.conn):
            self.conn.close()

class ConnectorManager:
    def __init__(self):
        self.connector = Connector()
    def __enter__(self):
        return self.connector
    def __exit__(self, type, value, traceback):
        success = True
        if (type):
            success = False
        self.connector.close()
        return success
