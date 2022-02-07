import time
import sinstagram.generator

if __name__ == "__main__":
    sinstagram.generator.generate(int(time.time()) - 31536000,
                                  1000,
                                  "data",
                                  500000,
                                  verbose=True)
