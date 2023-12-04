cmake_minimum_required(VERSION 3.23)
project(Git)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories(.vscode)
include_directories(Algorithm)
include_directories("Listas Monitoria")

add_executable(Git
        .idea/.gitignore
        .idea/Git.iml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        .vscode/Terminal.txt
        Algorithm/List/ArrayList.c
        Algorithm/List/ArrayQueue.c
        Algorithm/List/ArrayStack.c
        Algorithm/List/LinkedList.c
        Algorithm/List/LinkedQueue.c
        Algorithm/List/LinkedStack.c
        Algorithm/Search/BinarySearch.c
        Algorithm/Sort/MergeSort.c
        Algorithm/Sort/QuickSort.c
        "Listas Monitoria/Exerc�cio Pr�ticos/Dicion�rios(hash).c"
        "Listas Monitoria/Exerc�cio Pr�ticos/Express�esP�s-fixas.c"
        "Listas Monitoria/Exerc�cio Pr�ticos/MaratonaCin.c"
        "Listas Monitoria/Exerc�cio Pr�ticos/Matricula.c"
        "Listas Monitoria/Lista 1/A - Discounts.c"
        "Listas Monitoria/Lista 1/B - Hacking the random number generator.c"
        "Listas Monitoria/Lista 2/A - Broken Keyboard.c"
        "Listas Monitoria/Lista 2/B - Take ABC.c"
        README.md)
