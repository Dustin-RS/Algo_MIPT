# Решение задачи 2E

По факту, конечно же в куче, главными алгоритмами являются SiftUp и SiftDown, поэтому их реализация важнее всего, потому что дальше все строится на ней.
С Сифт апом проблем нет, Рекурсивно поднимаем эл-т вверх кучи, до тех пор пока он не станет корневым, или сверху есть эл-т меньше. 
С Сифт дауном посложнее. Нам нужно процедить эл-т вниз. И в моем алгоритме просто рассматриваютс случаи, когда лев ребенок больше правого то рекурсивно идем по правой стороне. Иначе наоборот. 
Понятно, что сифт ап и сифт даун работают за логарифм(по глубине дерева).
Далее алгоритмы вставки, удаление минимума, получение минимума и размера.
Получение минимума и размера, очевидно, просто берем корень, а для размера, длину массива.
Для вставки, вставляем эл-т в конце массива, а затем вызываем сифтап по последнему индексу(куда добавили новый эл-т)
Для того чтобы вытащить мин эл-т, просто меняем первый и последний эл-т массива местами, удаляем последний жл-т массива и далее сфит даунаем корень(т.к он у нас поменялся)
Понятное дело, что Инсерт и Экстракт работают также за высоту.
