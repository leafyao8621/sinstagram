import psycopg2
from .._credentials import *

class Connector:
    def __init__(self):
        self.conn = psycopg2.connect(user=user,
                                     password=password,
                                     host=host,
                                     database=database,
                                     options=options)
        self.cur = self.conn.cursor()
    def bulk_upload(self):
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
