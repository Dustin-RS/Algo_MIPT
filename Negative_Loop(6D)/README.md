Дан ориентированный граф. Определить, есть ли в нем цикл отрицательного веса, и если да, то вывести его.

Формат ввода
В первой строке содержится число N (1 ≤ N ≤ 100) — количество вершин графа. В следующих N строках находится по N чисел — матрица смежности графа. Веса ребер по модулю меньше 100000. Если ребра нет, соответствующее значение равно 100000.

Формат вывода
В первой строке выведите YES, если цикл существует, или NO, в противном случае.

При наличии цикла выведите во второй строке количество вершин в нем (считая одинаковые — первую и последнюю), а в третьей строке — вершины, входящие в этот цикл, в порядке обхода. Если циклов несколько, то выведите любой из них.
