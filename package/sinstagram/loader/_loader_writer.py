import typing

def process(x: str) -> str:
    """[summary]

    Args:
        x (str): [description]

    Returns:
        str: [description]
    """
    return x if int(x) else "\\N"

class Writer:
    def __init__(self):
        """[summary]
        """
        self.fout_users = open("/tmp/.users", "w")
        self.fout_posts = open("/tmp/.posts", "w")
        self.fout_post_media = open("/tmp/.post_media", "w")
        self.fout_post_comments = open("/tmp/.post_comments", "w")
        self.fout_post_comment_media = open("/tmp/.post_comment_media", "w")
        self.fout_followings = open("/tmp/.followings", "w")
        self.fout_post_likes = open("/tmp/.post_likes", "w")
    def write_users(self,
                    user_name: str,
                    sex: str,
                    gender: str,
                    education_level: str,
                    dob: str,
                    created: str):
        """[summary]

        Args:
            user_name (str): [description]
            sex (str): [description]
            gender (str): [description]
            education_level (str): [description]
            dob (str): [description]
            created (str): [description]
        """
        self.fout_users.write(f"\"{user_name}\",")
        self.fout_users.write(f"{process(sex)},{process(gender)},")
        self.fout_users.write(f"{process(education_level)},\"{dob}\",")
        self.fout_users.write(f"\"{created}\"\n")
    def write_posts(self,
                    user_id: str,
                    textual_content: str,
                    time_posted: str):
        """[summary]

        Args:
            user_id (str): [description]
            textual_content (str): [description]
            time_posted (str): [description]
        """
        self.fout_posts.write(f"{user_id},")
        self.fout_posts.write(f"\"{textual_content}\",")
        self.fout_posts.write(f"\"{time_posted}\"\n")
    def write_post_media(self,
                         post_id: str,
                         urls: typing.List):
        """[summary]

        Args:
            post_id (str): [description]
            urls (typing.List): [description]
        """
        for i in urls:
            if (i):
                self.fout_post_media.write(f"{post_id},")
                self.fout_post_media.write(f"\"{i}\"\n")
    def write_post_comments(self,
                            post_id: str,
                            user_id: str,
                            textual_content: str,
                            time_commented: str):
        """[summary]

        Args:
            post_id (str): [description]
            user_id (str): [description]
            textual_content (str): [description]
            time_commented (str): [description]
        """
        self.fout_post_comments.write(f"{post_id},")
        self.fout_post_comments.write(f"{user_id},")
        self.fout_post_comments.write(f"\"{textual_content}\",")
        self.fout_post_comments.write(f"\"{time_commented}\"\n")
    def write_post_comment_media(self,
                                 post_comment_id: str,
                                 urls: typing.List):
        """[summary]

        Args:
            post_comment_id (str): [description]
            urls (typing.List): [description]
        """
        for i in urls:
            if (i):
                self.fout_post_comment_media.write(f"{post_comment_id},")
                self.fout_post_comment_media.write(f"\"{i}\"\n")
    def write_followings(self,
                         from_id: str,
                         to_id: str,
                         time_initiated: str):
        """[summary]

        Args:
            from_id (str): [description]
            to_id (str): [description]
            time_initiated (str): [description]
        """
        self.fout_followings.write(f"{from_id},")
        self.fout_followings.write(f"{to_id},")
        self.fout_followings.write(f"\"{time_initiated}\"\n")
    def write_post_likes(self,
                         post_id: str,
                         user_id: str,
                         time_liked: str):
        """[summary]

        Args:
            post_id (str): [description]
            user_id (str): [description]
            time_liked (str): [description]
        """
        self.fout_post_likes.write(f"{post_id},")
        self.fout_post_likes.write(f"{user_id},")
        self.fout_post_likes.write(f"\"{time_liked}\"\n")
    def close(self):
        """[summary]
        """
        self.fout_users.close()
        self.fout_posts.close()
        self.fout_post_media.close()
        self.fout_post_comments.close()
        self.fout_post_comment_media.close()
        self.fout_followings.close()
        self.fout_post_likes.close()

class WriterManager:
    def __init__(self):
        """[summary]
        """
        self.writer = Writer()
    def __enter__(self):
        """[summary]

        Returns:
            [type]: [description]
        """
        return self.writer
    def __exit__(self, type, value, traceback):
        """[summary]

        Args:
            type ([type]): [description]
            value ([type]): [description]
            traceback ([type]): [description]

        Returns:
            [type]: [description]
        """
        success = True
        if (type):
            success = False
        self.writer.close()
        return success
