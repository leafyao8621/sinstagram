def process(x: str):
    return x if int(x) else "\\N"

class Writer:
    def __init__(self):
        self.fout_users = open("/tmp/.users", "w")
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
    def close(self):
        self.fout_users.close()

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
