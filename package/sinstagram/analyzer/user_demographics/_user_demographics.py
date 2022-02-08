from matplotlib.pyplot import connect
from .._analyzer_connector import *

def by_sex_gender(display: bool=True, fn: typing.Union[str, None]=None):
    """[summary]

    Args:
        display (bool, optional): [description]. Defaults to True.
        fn (typing.Union[str, None], optional): [description]. Defaults to None.
    """
    with ConnectorManager() as connector:
        connector.execute(\
            '''
            SELECT
                CASE
                    WHEN
                        B.description IS NULL
                    THEN
                        'N/A'
                    ELSE
                        B.description
                END AS sex,
                CASE
                    WHEN
                        C.description IS NULL
                    THEN
                        'N/A'
                    ELSE
                        C.description
                END AS gender,
                cnt
            FROM
                ((SELECT
                    sex,
                    gender,
                    COUNT(*) AS cnt
                FROM
                    users
                GROUP BY
                    sex,
                    gender) A LEFT JOIN
                (SELECT
                    id,
                    description
                FROM
                    sexes) B ON
                A.sex = B.id LEFT JOIN
                (SELECT
                    id,
                    description
                FROM
                    genders) C ON
                A.gender = C.id)
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

def by_education_level(display: bool=True, fn: typing.Union[str, None]=None):
    """[summary]

    Args:
        display (bool, optional): [description]. Defaults to True.
        fn (typing.Union[str, None], optional): [description]. Defaults to None.
    """
    with ConnectorManager() as connector:
        connector.execute(\
            '''
            SELECT
                CASE
                    WHEN
                        B.description IS NULL
                    THEN
                        'N/A'
                    ELSE
                        B.description
                END AS education_level,
                cnt
            FROM
                ((SELECT
                    education_level,
                    COUNT(*) AS cnt
                FROM
                    users
                GROUP BY
                    education_level
                ORDER BY
                    education_level) A LEFT JOIN
                (SELECT
                    id,
                    description
                FROM
                    education_levels) B ON
                A.education_level = B.id);
            '''
        )
        fout = None
        if (fn):
            fout = open(fn, "w")
        if (display):
            print("|", end="")
        for i, ii in enumerate(connector.cur.description):
            if (display):
                print(f" {ii[0]:30s} |" if not i else f" {ii[0]:10s} |", end="")
        if (fout):
            print(*(f"\"{i[0]}\"" for i in connector.cur.description),
                  sep=",",
                  file=fout)
        if (display):
            print("")
        for i in connector.cur:
            if (display):
                print("| ", end="")
                print(*(f"{j:30s}" if isinstance(j, str) else f"{j:10d}"
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
