import glob
from ._loader_connector import *
from ._loader_writer import *

def load_dir(dir: str, verbose: bool=False):
    with ConnectorManager() as connector:
        for i in sorted(glob.glob(f"{dir}/*.csv")):
            if (verbose):
                print(f"Loading {i}")
            with open(i, "r") as fin,\
                 WriterManager() as writer:
                while True:
                    line = fin.readline()
                    if (not line):
                        break
                    data = line[1:-2].split("\",\"")
                    if (data[0] == "0"):
                        writer.write_users(*data[1:])
                    elif (data[0] == "3"):
                        writer.write_posts(*data[2:5])
                        writer.write_post_media(data[1], data[5:])
                    elif (data[0] == "5"):
                        writer.write_post_comments(*data[2:6])
                        writer.write_post_comment_media(data[1], data[6:])
                    elif (data[0] == "7"):
                        writer.write_followings(*data[1:])
                    elif (data[0] == "9"):
                        writer.write_post_likes(*data[1:])
            connector.bulk_upload()
