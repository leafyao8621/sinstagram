from ._loader_connector import *


def load_dir(dir: str):
    with ConnectorManager() as connector:
        print("load")

