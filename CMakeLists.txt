cmake_minimum_required(VERSION 3.27)
project(Git C)

set(CMAKE_C_STANDARD 11)

add_executable(Git
        "Algorithm/Dictionary/Closed Hashing.c"
        "Algorithm/Dictionary/Open Hashing.c"
        Algorithm/List/ArrayList.c
        Algorithm/List/ArrayQueue.c
        Algorithm/List/ArrayStack.c
        Algorithm/List/LinkedList.c
        Algorithm/List/LinkedQueue.c
        Algorithm/List/LinkedStack.c
        Algorithm/Search/BinarySearch.c
        Algorithm/Sort/MergeSort.c
        Algorithm/Sort/QuickSort.c
        Algorithm/Tree/AVL.c
        "Algorithm/Tree/Binary Search Trees (BST).c"
        "Listas Monitoria/Exerc�cio Pr�ticos/Dicion�rioAVL.c"
        "Listas Monitoria/Exerc�cio Pr�ticos/Dicion�rios(hash).c"
        "Listas Monitoria/Exerc�cio Pr�ticos/Express�esP�s-fixas.c"
        "Listas Monitoria/Exerc�cio Pr�ticos/MaratonaCin.c"
        "Listas Monitoria/Exerc�cio Pr�ticos/Matricula.c"
        "Listas Monitoria/Lista 1/A - Discounts.c"
        "Listas Monitoria/Lista 1/B - Hacking the random number generator.c"
        "Listas Monitoria/Lista 2/A - Broken Keyboard.c"
        "Listas Monitoria/Lista 2/B - Take ABC.c"
        "Listas Monitoria/Lista 3/A - Hash it!.c"
        "Listas Monitoria/Lista 3/B - Traversing Tree.c"
        "Listas Monitoria/Lista 4/A - AVL Tree.c"
        "Listas Monitoria/Lista 4/B - Add All.c")
