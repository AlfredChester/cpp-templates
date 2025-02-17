# import os

# WARNING = """
# WARNING: This script is only guaranteed to work
#          on alfred's macBook. It may fail or cause
#          unexpected effects on other devices. It is
#          suggested to view the source code before
#          running.
# """

# CHECK = "Sure to continue? (y/N)"


# def checkUser() -> bool:
#     try:
#         return os.environ["USER"] == "alfred"
#     except:
#         return False


# def main() -> int:
#     if not checkUser():
#         print(WARNING)
#         res = input(CHECK)
#         if res != "Y" and res != "y":
#             return 0
#     print("Composing to cpp.json")
#     return 0


# if __name__ == "__main__":
#     main()
