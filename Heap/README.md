Реализуйте структуру данных «пирамида». Напишите программу, реализовав все указанные здесь методы. Возможные команды для программы:

insert n — добавить в пирамиду число n (1 ≤ n ≤ 109) (значение n задается после команды). Программа должна вывести ok.
extract_min — удалить из пирамиды минимальный элемент. Программа должна вывести его значение.
get_min — программа должна вывести значение минимального элемента, не удаляя его из пирамиды.
size — программа должна вывести количество элементов в пирамиде.
clear — программа должна очистить пирамиду и вывести ok.
Перед исполнением операций extract_min и get_min программа должна проверять, содержится ли в пирамиде хотя бы один элемент. Если во входных данных встречается операцияextract_min или get_min, и при этом пирамида пуста, то программа должна вместо числового значения вывести строку error.

Формат ввода
В первой строке входных данных записано единственное число M (1 ≤ M ≤ 2 ⋅ 105) — количество команд.

В следующих М строках дано по одной команде из тех, что идут выше.

Формат вывода
Для каждой команды выведите одну строчку — результат ее выполнения.
