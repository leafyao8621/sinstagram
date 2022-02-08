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
    def execute(self, query: str,
                args: typing.Union[typing.Tuple, None]=None):
        """[summary]

        Args:
            query (str): [description]
            args (typing.Union[typing.Tuple, None], optional): [description]. Defaults to None.
        """
        self.cur.execute(query, vars=args)
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
