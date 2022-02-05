import time
import sinstagram.generator

if __name__ == "__main__":
    sinstagram.generator.generate(int(time.time()) - 31536000,
                                  1000,
                                  "data",
                                  1000000,
                                  verbose=False)
