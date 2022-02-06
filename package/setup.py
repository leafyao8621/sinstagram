from setuptools import setup, Extension

base = Extension('sinstagram.generator._base',
                 sources=["sinstagram/generator/src/events/handlers/handler_create_comment.c",
                          "sinstagram/generator/src/events/handlers/handler_create_post.c",
                          "sinstagram/generator/src/events/handlers/handler_create_user.c",
                          "sinstagram/generator/src/events/handlers/handler_follow.c",
                          "sinstagram/generator/src/events/handlers/handler_like_post.c",
                          "sinstagram/generator/src/events/handlers/handler_remove_comment.c",
                          "sinstagram/generator/src/events/handlers/handler_remove_post.c",
                          "sinstagram/generator/src/events/handlers/handler_remove_user.c",
                          "sinstagram/generator/src/events/handlers/handler_unfollow.c",
                          "sinstagram/generator/src/events/handlers/handler_unlike_post.c",
                          "sinstagram/generator/src/events/handlers/handler_update_user.c",
                          "sinstagram/generator/src/events/handlers/handlers.c",
                          "sinstagram/generator/src/events/initializers/initializer_create_comment.c",
                          "sinstagram/generator/src/events/initializers/initializer_create_post.c",
                          "sinstagram/generator/src/events/initializers/initializer_create_user.c",
                          "sinstagram/generator/src/events/initializers/initializer_follow.c",
                          "sinstagram/generator/src/events/initializers/initializer_like_post.c",
                          "sinstagram/generator/src/events/initializers/initializer_remove_comment.c",
                          "sinstagram/generator/src/events/initializers/initializer_remove_post.c",
                          "sinstagram/generator/src/events/initializers/initializer_remove_user.c",
                          "sinstagram/generator/src/events/initializers/initializer_unfollow.c",
                          "sinstagram/generator/src/events/initializers/initializer_unlike_post.c",
                          "sinstagram/generator/src/events/initializers/initializer_update_user.c",
                          "sinstagram/generator/src/events/initializers/initializers.c",
                          "sinstagram/generator/src/events/events.c",
                          "sinstagram/generator/src/model/model.c",
                          "sinstagram/generator/src/simulator/simulator.c",
                          "sinstagram/generator/src/util/generator.c",
                          "sinstagram/generator/src/util/mt19937.c",
                          "sinstagram/generator/src/main.c"])

setup(name="sinstagram",
      version="0.1",
      packages=["sinstagram",
                "sinstagram.generator",
                "sinstagram.loader"],
      ext_modules=[base])
