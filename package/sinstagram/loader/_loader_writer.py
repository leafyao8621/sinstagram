def process(x: str):
    return x if int(x) else "\\N"

class Writer:
    def __init__(self):
        self.fout_users = open("/tmp/.users", "w")
        self.fout_posts = open("/tmp/.posts", "w")
        self.fout_post_media = open("/tmp/.post_media", "w")
    def write_users(self,
                    user_name,
                    sex,
                    gender,
                    education_level,
                    dob,
                    created):
        self.fout_users.write(f"\"{user_name}\",")
        self.fout_users.write(f"{process(sex)},{process(gender)},")
        self.fout_users.write(f"{process(education_level)},\"{dob}\",")
        self.fout_users.write(f"\"{created}\"\n")
    def write_posts(self,
                    user_id,
                    textual_content,
                    time_posted):
        self.fout_posts.write(f"{user_id},")
        self.fout_posts.write(f"\"{textual_content}\",")
        self.fout_posts.write(f"\"{time_posted}\"\n")
    def write_post_media(self,
                         post_id,
                         urls):
        for i in urls:
            if (i):
                self.fout_post_media.write(f"{post_id},")
                self.fout_post_media.write(f"\"{i}\"\n")
    def close(self):
        self.fout_users.close()
        self.fout_posts.close()
        self.fout_post_media.close()

class WriterManager:
    def __init__(self):
        self.writer = Writer()
    def __enter__(self):
        return self.writer
    def __exit__(self, type, value, traceback):
        success = True
        if (type):
            success = False
        self.writer.close()
        return success
