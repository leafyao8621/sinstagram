from matplotlib.pyplot import connect
from .._analyzer_connector import *

def by_id(display: bool=True, fn: typing.Union[str, None]=None):
    """[summary]

    Args:
        display (bool, optional): [description]. Defaults to True.
        fn (typing.Union[str, None], optional): [description]. Defaults to None.
    """
    with ConnectorManager() as connector:
        connector.execute(\
            '''
            SELECT
                id,
                SUM(
                    CASE
                        WHEN
                            user_id IS NULL
                        THEN
                            0
                        ELSE
                            1
                    END
                ) AS cnt
            FROM
                ((SELECT
                    id
                FROM
                    users) A LEFT JOIN
                (SELECT
                    user_id
                FROM
                    posts) B ON
                A.id = B.user_id)
            GROUP BY
                id
            ORDER BY
                cnt,
                id;
            '''
        )
        fout = None
        if (fn):
            fout = open(fn, "w")
        if (display):
            print("|", end="")
        for i in connector.cur.description:
            if (display):
                print(f" {i[0]:10s} |", end="")
        if (fout):
            print(*(f"\"{i[0]}\"" for i in connector.cur.description),
                  sep=",",
                  file=fout)
        if (display):
            print("")
        for i in connector.cur:
            if (display):
                print("| ", end="")
                print(*(f"{j:10s}" if isinstance(j, str) else f"{j:10d}"
                        for j in i),
                      sep=" | ",
                      end="")
                print(" |")
            if (fout):
                print(*(f"\"{j}\"" for j in i),
                      sep=",",
                      file=fout)
        if (fout):
            fout.close()

def by_hour(display: bool=True, fn: typing.Union[str, None]=None):
    """[summary]

    Args:
        display (bool, optional): [description]. Defaults to True.
        fn (typing.Union[str, None], optional): [description]. Defaults to None.
    """
    with ConnectorManager() as connector:
        connector.execute(\
            '''
            SELECT
                DATE_PART('hour', time_posted) AS hour_posted,
                COUNT(*) AS cnt
            FROM
                posts
            GROUP BY
                hour_posted
            ORDER BY
                hour_posted
            '''
        )
        fout = None
        if (fn):
            fout = open(fn, "w")
        if (display):
            print("|", end="")
        for i in connector.cur.description:
            if (display):
                print(f" {i[0]:10s} |", end="")
        if (fout):
            print(*(f"\"{i[0]}\"" for i in connector.cur.description),
                  sep=",",
                  file=fout)
        if (display):
            print("")
        for i in connector.cur:
            if (display):
                print("| ", end="")
                print(*(f"{j:10s}" if isinstance(j, str) else f"{j:10.0f}"
                        for j in i),
                      sep=" | ",
                      end="")
                print(" |")
            if (fout):
                print(*(f"\"{j}\"" for j in i),
                      sep=",",
                      file=fout)
        if (fout):
            fout.close()
