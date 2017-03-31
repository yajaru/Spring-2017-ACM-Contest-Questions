import random
import sys

import names



def main():
    num_people = int(sys.argv[1])
    print(num_people)
    people = [names.names[int(random.random() * len(names.names))] for i in range(num_people)]

    for each in people:
        print(each, end=' ')
    print("")

    for each in people:
        for each2 in people:
            if each != each2:
                print(each, each2, "%0.5f" % random.random())


if __name__ == '__main__':
    main()
