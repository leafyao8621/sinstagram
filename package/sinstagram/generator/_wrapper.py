import sinstagram.generator._base

def generate(start_time: int,
             seed: int,
             dir: str,
             iter: int,
             verbose: bool=False):
    """[summary]

    Args:
        start_time (int): [description]
        seed (int): [description]
        dir (str): [description]
        iter (int): [description]
        verbose (bool, optional): [description]. Defaults to False.
    """
    sinstagram.generator._base.generate(start_time,
                                        seed,
                                        dir,
                                        iter,
                                        verbose)
