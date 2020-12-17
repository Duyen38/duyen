# Аппроксимации временных рядов с помощью в-сплайнов.
Ключевые слова: аппроксимация, временные ряды, интерполяция, точность, в-сплайн, 
## Аннотация
Временные ряды обычно представляют собой большие ряды данных и меняются нерегулярность в разные времени. Для обработки необходима помощь методов интерполяции аппроксимации данных. В данной статье были рассмотрены современные методы  интерполяции и модели, их достоинства и недостатки. Вследствие был сделан вывод о целесообразности разработки нового решения, которое представляет временных рядов с высокой точностью. В результате была выдвинута метода  для решения этой проблемы и обеспечения лучший обзор отслеживаемых данных и получить повышения эффективности в работе. 
## Введение
Как известно, временной ряд — собранный в разные моменты времени статистический материал о значении каких-либо параметров исследуемого процесса. В современном времени временные ряды являются важной формой данных в различных областях промышленности и исследований и представления временных рядов вызывает большой интерес. В последние десятилетия интеллектуальный анализ данных временных рядов привлек внимание и стал быстро развиваться. Временные ряды по своей природе являются часто интерционными, т. е. значения временного ряда в некоторые моменты времени зависят от значений ряда в предыдущие моменты времени. Свойства временных рядов, такие как: большой объем данных, случайные данные, тренд, различные сглаживания, сезонность, медленно и быстро меняющиеся компоненты, циклическая нерегулярность, приводят к представлению данные временных рядов становятся все более сложными.
Объектом исследования являются аппроксимации временных рядов с помощью B-сплайна. Предметом исследования является представление аппроксимации данных путем исключения случайных величин при сохранении точности важных характеристик исходных. Целью данной работы является предложение алгоритма применения формирование модели аппроксимации временных рядов с помощью в-сплайнов.
Таким образом, необходимо выполнить следующие  задачи
Проведение анализ существующих решений представления временных рядов.
Изучение в-сплайны.
Разработка решения задачи аппроксимации временных рядов с помощью в-сплайнов.

## Сравнение аналогов
## Принцип отбора аналогов
Временные ряды часто содержат недостающие данные или данные, полученные нерегулярно. Для решения этой проблемы давно используются методы интерполяции. Рассмотрение эффективных методов интерполяции, обычно используемые в задачах аппроксимации данных.
Поиск методов и алгоритмов аналогов осуществлялся в сети интернет и наличие для чтения по следующим запросам: "Аппроксимация временных рядов", "Методы интерполяция", "Интерполяция временных рядов".
## Аналоги
### Линейная интерполяция
Простейшим и часто используемым видом локальной интерполяции является линейная[1] (или кусочно-линейная) интерполяция с использованием линейных полиномов для построения новых точек данных в пределах диапазона дискретного набора известных точек данных. Соединяя отрезками прямых точки для соседних узлов, можно получить график кусочно-линейной интерполяции. Однако практика показывает, этот метод дает большую погрешность.
### Лагранжа
Интерполяционный многочлен Лагранжа[2] — многочлен минимальной степени, принимающий данные значения в данном наборе точек. В интерполяции методом Лагранжа значения параметра должны быть заданы для каждой точки интерполяции. Форма интерполяционной кривой существенно зависит от выбранных значений параметра.
### Безье
Метод Безье[3] — интерполяция конечной точки. Данные отображаются в кривых,  располагающихся внутри фигуры, образованной линиями, соединяющими контрольные точки и непрерывность заполнения сегмента между начальной и конечной точками, расположение контрольных точек  непосредственно влияет на форму кривой. Это один из удобных методов для аппроксимации данных[6].
При аппроксимации методом Безье на значения координат каждой точки кривой оказывают влияние все вершины ломаной Безье. Это затрудняет корректирование отдельных участков кривой.
### Кубический сплайн
Кубический сплайн[4] — гладкая функция, область определения которой разбита на конечное число отрезков, на каждом из которых она совпадает с некоторым кубическим многочленом (полиномом) непрерывного наклона и кривизны в каждой контрольной точке или узле. Метод интерполяция для построение кривых из заданых узлах одномерной сетки. Однако ряд данных с большими шагами кубический сплайн не удовлетворительно позволяет восстанавливать функции.
### Weighted piecewise linear (WPL) 
Метод интерполяции в реальном времени для выбора неоднородных биосигналов в приложениях биологических сигналов[5]. Метод предназначен оценки кривизны  в точках перегибов (с лучшим приближением, чем линейная интерполяция) и  взвешенной кусочно-линейной интерполяции. Плюсом данного метода является возможность найти лучший баланс между вычислительной эффективностью и точностей полученного графика.
## Критерии сравнения аналогов
Полезный метод интерполяции должен соответствовать критериям:
- Вид интерполяции, который при изменении каждого точки интерполяция не должна быть полно пересчитанаю ряда.
- Кривая построенной функции проходит через имеющиеся точки данных и должна сохранять характеристики исходного ряда.
- Вычисление больших рядов должно быть эффективным и быстрым.
### Вид интерполяции
Порядок полинома зависит от вида интерполяции. С глобальной интерполяцией количество точек в временном ряду увеличивается, увеличивается и порядок полинома и при изменении каждой точки интерполяция должна быть пересчитана. Иначе в случае локальной интерполяции на каждом интервале строится отдельный интерполяционный полином невысокой степени, можно производить локальные изменения без полного пересчета.
### Представление кривых
Кривые - это базовые объекты, которые являются результатом процесса интерполяции и отображают точность результатов интерполяции по сравнению с исходного ряда.
### Вычислительные методы алгоритма
Вычислительные методы, оценивающие сложность и определяющие необходимые технологии в процессе определения параметров модели и пропущенных значений одновременно.
### Оценка сложности алгоритма
Оценка сложности алгоритма является важным фактором, определяющим скорость сравнения программ.
## Таблица сравнения по критериям
| Критерии | Линейная интерполяция |  Лагранжа  |   Безье   | Кубический сплайн |   WPL 	|
|----------|-----------------------|------------|-----------|-------------------|-----------|
| Вид интерполяции | локальная | глобальная | глобальная | локальная | локальная |
| Кривая | Ломаная кривая | Линейная комбинация кривая | Кривая, располагающихся внутри фигуры, образованной линиями, соединяющими контрольные точки| Кривая, представляютщая из полином функции 3-й степени | Кривая, представляютщая из синусоидов |
| Вычислительные методы |   -   | Факториальная сложность числителя и знаменателя | Вычислительная математика полиномиальных функций большой степени | Трехдиагональная матрица методом прогонки в поиске коэффицентов | Дополнительный расчет наклона, интервальная сегментация и генерация кусочного наклона между точакми данных |
| Сложность алгоритма | O(n) | O(n^2) | O(t^n) где t - параметр времени | O(n) в решении трехдиагонального матрично-векторного уравнения | Сложность зависит от характеристик собранных данных (P, QRS and T волн)|   
## Выводы по итогам сравнения
По результатам сравнения можно сделать вывод, главным различием между алгоритмами является время выполнения и вычислительные методы, поэтому выбор используемого интерполяци необходимо совершать с учётом цели аппроксимация временных рядов. Все методы существуют погрешность интерполяции, соответствующие различным типам данных, например, большому количеству точек данных, быстрые изменения значений на малых промежутках и т. д. 
Метод линейной интерполяции является наиболее простейшим в использовании, но чем более «искривленной» функция, тем хуже становятся аппроксимации, сделанные с помощью линейной интерполяции.
Для ряды данных небольшим объёмом , оптимальным будет метод интерполяции Безье. Кривые высших степеней при обработке требуют большего объёма вычислений и для практических целей используются реже.
Для реального времени ряда в соответствии с клинически обоснованным диагнозом по биосигналам , лучше всего и оптимально подойдет метод интерполяции WPL.

## Выбор метода решения
Разрабатываемый модель должен осуществлять с помощью  В-сплайнов для аппроксимации временных рядов с балансированием сложности алгоритма и точности характеристик данных.
Таким образом данное решение должно обладать следующими качествами:
1. B-сплайн — сплайн-функция, имеющая наименьший носитель для заданной степени, порядка гладкости и разбиения области определения.
2. Интерполяция B-сплайном с заданными пользователем узлами. Кривая B-сплайна, созданная из контрольного многоугольника, степень которой не зависит от количества вершин контрольного многоугольника и, следовательно, могут быть выбраны произвольно.
3. B-сплайн может быть создан по начальной и конечной точкам и касается начального и конечного вектора контрольного многоугольника.
4. B-сплайн обладает желательной локальностью возможно производить локальные изменения кривой без полного пересчета.
5. С помощью В-сплайна решает более общая задача - задача аппроксимации данных, обеспечивает более точное приближение ломаной, связанные с балансированием сложности алгоритма и точности представления кривых.

## Описание метода решения
Аппроксимационная B-сплайн-кривая[7] со степенью k каждого кусочно-полиномиального определяется: 
p(u) = \sum\limits_{i=0}^{n} r_i N_{i,k} (u)
где r_i  - точки контрольного многоугольника, а N_{i,k} (u) называются весовыми функциями B-сплайна B-сплайнов. Контрольный многоугольник имеет n + 1 контрольную точку. N_{i,k} (u) определяются на основе последовательности узлов:
U_{knot}={u_0,u_1,…,u_m}
с рекурсивной формулой:
N_{i,k}(u) = \{ {1, u_i \leq u \leq u_{i-1}} \\ 0,  otherwise
N_{i,k}(u) = \frac{(u-u_i)N_{i,k-1}(u)}{u_{i+k}-u_i}+  \frac{(u_{i+k+1}-u)N_{i+1,k-1} (u)}{u_{i+k+1}-u_{i+1}}

Когда знаменатель равен нулю, предполагается, что дробь имеет нулевое значение.
B-сплайн-функции порядка k определяются уравнением:
B_k (x)= \frac{1}{k} \sum_{i=0}^{k+1} (-1)^k \binom{k+1}{i}(x-i+ \frac{k+1}{2})^k H(x-i+ \frac{k+1}{2})
где k - степень каждого кусочного полинома, а H (x) - ступенчатая функция Хевисайда.
Тогда B-сплайн-функции любого порядка могут быть заданы рекурсивным соотношением:
B_k (x)= (B_{k-1} * B_k)(x),  где оператор * обозначает свертку	
Если k (x) используется для весовой функции N_(i,k) (u), аппроксимационная кривая B-сплайна будет:
p(x) = \sum\limits_{i=0}^{n} r_i B_k(x-i)
где r_i - бесконечная последовательность контрольных точек. Соответственно, для каждого значения k кусочно-кривой p_i (u) будет аппроксимировать контрольный многоугольник.
 ![alt](http://https://github.com/Duyen38/duyen/blob/master/paper/%D1%80%D0%B8%D1%811.png)
Рисунок 1. B-сплайн-функции порядка k от 2 до 5
Другими словами, B-сплайн-функция порядка k может быть получена путем свертки B-сплайн функции порядка 0 с самой собой k раз. Это хорошо известное свойство свертки B-сплайнов, которое будет использоваться для выполнения интерполяции B-сплайнов. На рисунке [Рисунок 1] показано несколько B-сплайн.
В процессе интерполяции начало с дискретного ряда, получаемой в разных интервалах реального времени f(k). Этот ряд представляет значения заданной функции в узловых точках. Основная цель теперь -  восстановление значения этой функции в произвольной позиции (точке). B-сплайн интерполяция основывается на функции p(x). Важным условием является то, что значения p(x) в узловых точках должны совпадать со значениями интерполированной функции f (x). Тогда мы имеется соотношение p(k)=f (k), где k обозначает узловые точки временных рядов. Чтобы интерполировать данную узловых точках функции f (k), необходимо вычислить последовательность r_i соответствующих коэффициентов B-сплайна. Эта последовательность однозначно определяется величиной f(k). 
## Заключение
В данной статье был проведен обзор предметной области и сравнение существующих решений с точки зрения возможности аппроксимации данных, а также их недостатков , вследствие был сделан вывод о необходимости нового, более оптимального решения для обработки аппроксимации временных рядов. В данной статье была выдвинута метода  для решения этой проблемы - метод интерполяции в-сплайнов. В будущем планируется разработать программную реализацию  аппроксимации временных рядов для применения на практике.
## Список литературы
1. Линейная интерполяция  / URL: https://ru.wikipedia.org/wiki/Линейная_интерполяция
2. Лагранжа / URL: https://ru.wikipedia.org/wiki/Интерполяционный_многочлен_Лагранжа
3. Безье  / URL: https://ru.wikipedia.org/wiki/Кривая_Безье
4. Кубический сплайн / URL:  https://en.wikiversity.org/wiki/Cubic_Spline_Interpolation
5. Onur Guven, Amir Eftekhar, Wilko Kindt, and Timothy G. Constandinou Computationally efficient real-time interpolation algorithm for non-uniform sampled biosignals  (Published online 2016)/ URL: https://www.ncbi.nlm.nih.gov/pmc/articles/PMC4916476/#C4 
6. Форрест А. Р.  Интерактивная интерполяция и аппроксимация полиномами Безье - Forrest A. R. Interactive interpolation and approximation by Bezier polinomials // The Computer Journal. 1972. V. 15. No. 1. P. 71–79. [Перевод на русский язык Н. В. Чашникова] 
7. Zeljka Mihajlovic, A. Goluban The B-spline interpolation in visualization - 1999 / URL:  https://www.researchgate.net/publication/322743690_The_B-spline_interpolation_in_visualization