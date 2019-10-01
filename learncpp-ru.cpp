
//////////////////
// Сравнение с C
//////////////////

// C++ практически представляет собой надмножество C и имеет схожий синтаксис
// для объявления переменных, примитивов и функций.

// Так же, как и в С, точкой входа в программу является функция с именем main,
// которая возвращает целочисленное значение.
// Это значение является кодом ответа программы.
// Смотрите https://goo.gl/JYGKyv для более подробной информации.
int main(int argc, char** argv)
{
    // Аргументы командной строки, переданные в программу, хранятся в переменных
	// argc и argv, так же, как и в C.
    // argc указывает на количество аргументов,
    // а argv является массивом C-подобных строк (char*), который непосредсвенно
	// содержит аргументы.
    // Первым аргументом всегда передается имя программы.
    // argc и argv могут быть опущены, если вы не планируете работать с аругментами
	// коммандной строки.
	// Тогда сигнатура функции будет иметь следующий вид: int main()

    // Возвращаемое значение 0 указывает на успешное завершение программы.
    return 0;
}

// Тем не менее, C++ имеет свои отличия:

// В C++ символьные литералы имеют тип char.
sizeof('c') == sizeof(char) == 1

// В C символьные литералы - целые числа.
sizeof('c') == sizeof(int)


// C++ имеет строгое прототипирование.
void func(); // функция, которая не принимает аргументов.

// В языке C
void func(); // функция, которая может принять сколько угодно аргументов.

// Использование nullptr вместо NULL в C++.
int* ip = nullptr;

// Стандартные заголовочные файлы С доступны в С++,
// но с префиксом "с" и не имеют суффикса .h.
#include <cstdio>

int main()
{
    printf("Hello, world!\n");
    return 0;
}

///////////////////////
// Перегрузка функций
///////////////////////

// С++ поддерживает перегрузку функций, при условии,
// что каждая функция принимает различные параметры.

void print(char const* myString)
{
    printf("String %s\n", myString);
}

void print(int myInt)
{
    printf("My int is %d", myInt);
}

int main()
{
    print("Hello"); // Использование void print(const char*)
    print(15); // Использование void print(int)
}

/////////////////////////////
// Аргументы функций по умолчанию
/////////////////////////////

// Вы можете предоставить аргументы по умолчанию для функции,
// если они не предоставлены при вызове функции.

void doSomethingWithInts(int a = 1, int b = 4)
{
    // Здесь что-то делаем с числами
}

int main()
{
    doSomethingWithInts();      // a = 1,  b = 4
    doSomethingWithInts(20);    // a = 20, b = 4
    doSomethingWithInts(20, 5); // a = 20, b = 5
}

// Аргументы по умолчанию должны быть в конце списка аргументов.

void invalidDeclaration(int a = 1, int b) // Ошибка!
{
}


/////////////
// Пространства имен
/////////////

// Пространства имен предоставляют отдельные области для переменной,
// функции и других объявлений.
// Пространства имен могут быть вложенными.

namespace First {
    namespace Nested {
        void foo()
        {
            printf("This is First::Nested::foo\n");
        }
    } // конец пространства имен Nested
} // конец пространства имен First

namespace Second {
    void foo()
    {
        printf("This is Second::foo\n")
    }
}

void foo()
{
    printf("This is global foo\n");
}

int main()
{
    // Включает все функци из пространства имен Second в текущую область видимости.
    // Обратите внимание, что простой вызов foo() больше не работает,
    // так как теперь не ясно, вызываем ли мы foo из пространства имен Second, или
	// из глобальной области видимости.
    using namespace Second;

    Second::foo(); // напечатает "This is Second::foo"
    First::Nested::foo(); // напечатает "This is First::Nested::foo"
    ::foo(); // напечатает "This is global foo"
}

///////////////
// Ввод и вывод
///////////////

// Ввод и вывод в C++ использует потоки
// cin, cout и cerr представляют потоки stdin, stdout и stderr.
// << - оператор вставки, >> - оператор извлечения.

#include <iostream> // Включение файла для работы с потоками Ввода\Вывода.

using namespace std; // Потоки доступны в пространстве имен std (стандартная библиотека)

int main()
{
   int myInt;

   // Выводит в stdout (или в терминал/на экран)
   cout << "Enter your favorite number:\n";
   // Принимает ввод
   cin >> myInt;

   // cout может принимать форматирование
   cout << "Your favorite number is " << myInt << "\n";
   // напечатает "Your favorite number is <myInt>"

    cerr << "Used for error messages";
}

//////////
// Строки
//////////

// Строки в C++ являются объектами и имеют много функций-членов.
#include <string>

using namespace std; // Строки также доступны в пространстве имен std (стандартная библиотека)

string myString = "Hello";
string myOtherString = " World";

// + используется для конкатенации строк.
cout << myString + myOtherString; // "Hello World"

cout << myString + " You"; // "Hello You"

// Строки в C++ могут изменяться и имеют семантику значений.
myString.append(" Dog");
cout << myString; // "Hello Dog"


/////////////
// Ссылки
/////////////

// Кроме указателей, доступных в C,
// C++ имеет _ссылки_.
// Это такой тип указателя, который не может быть переназначен после инициализации
// и не может иметь значения null.
// Ссылки имеют схожий с переменными синтаксис:
// * больше не используется для разыменования и
// & (адрес) не используется для назначения.

using namespace std;

string foo = "I am foo";
string bar = "I am bar";


string& fooRef = foo; // Здесь создается ссылка на foo.
fooRef += ". Hi!"; // Изменяет foo по ссылке
cout << fooRef; // Печатает "I am foo. Hi!"

// Не переназначает "fooRef". Это то же самое, что и "foo = bar", и
//   foo == "I am bar"
// после этой строчки.
cout << &fooRef << endl; // Печатает адрес foo
fooRef = bar;
cout << &fooRef << endl; // По-прежнему печатает адрес foo
cout << fooRef;  // Печатает "I am bar"

// Адрес fooRef остается тем же, то есть он по-прежнему ссылается на foo.


const string& barRef = bar; // Создает константную ссылку.
// Так же, как и в C, константные значения (а также указатели и ссылки) не могут быть изменены.
barRef += ". Hi!"; // Ошибка, константная ссылка не может быть изменена.

// Обходной путь: Прежде чем мы рассмотрим указатели более детально, нам нужно ознакомиться
// с концепцией, известной как "временный объект". Представьте, что мы имеем следующий код
string tempObjectFun() { ... }
string retVal = tempObjectFun();

// Вот что на самом деле происходит во второй строке:
//   - tempObjectFun возвращает строковый объект
//   - из возвращаемого объекта создается новая строка в качестве аргумента конструктору
//   - возвращаемый объект уничтожается
// Возвращаемый объект называется временным объектом. Временные объекты создаются,
// когда функция возвращает объект, и уничтожаются в конце выполнения обрамляющего
// выражения (По крайней мере, так это описывает спецификация, хотя компиляторы могут
// изменять это поведение. Для более подробной информации смотрите "оптимизация
// возвращаемого значения".) Таким образом в этом коде:
foo(bar(tempObjectFun()))

// предполагая, что foo и bar существуют, объект, возвращаемый tempObjectFun, передается
// в bar, и уничтожается перед вызовом foo.

// Возвращаемся к указателям. Исключением для правила "в конце выполнения обрамляющего
// выражения" является временный объект, привязанный к ссылке const, в этом случае
// его жизненный цикл продлевается до текущей области видимости:

void constReferenceTempObjectFun() {
  // constRef получает временный объект, и он действителен до конца этой функции.
  const string& constRef = tempObjectFun();
  ...
}

// В C++11 предоставлен еще один тип ссылок специально для временных объектов.
// objects. Вы не можете объявить переменную этого типа, но он имеет приоритет
// в резолюции перегрузки:

void someFun(string& s) { ... }  // Обычная ссылка
void someFun(string&& s) { ... }  // Ссылка на временный объект

string foo;
someFun(foo);  // Выполняет версию с обычной ссылкой
someFun(tempObjectFun());  // Выполняет версию с временной ссылкой.

// Например, существуют следующие две версии конструктора std::basic_string:
basic_string(const basic_string& other);
basic_string(basic_string&& other);

// Идея в том, что если мы конструируем новую строку из временного объекта (который
// так или иначе будет уничтожен), мы можем использовать более эффективный конструктор,
// который "спасает" части этой временной строки. Эта концепция была названа
// "move semantics".

/////////////////////
// Перечисления
/////////////////////

// Перечисления - способ объявления констант и установки их значений, в основном
// использующийся для упрощения чтения кода.
enum ECarTypes
{
  Sedan,
  Hatchback,
  SUV,
  Wagon
};

ECarTypes GetPreferredCarType()
{
	return ECarTypes::Hatchback;
}

// На момент выхода C++11 есть простой способ назначения типа перечисления, что
// полезно в случае сериализации данных и преобразований между конечным типом и
// соответствующими константами.
enum ECarTypes : uint8_t
{
  Sedan, // 0
  Hatchback, // 1
  SUV = 254, // 254
  Hybrid // 255
};

void WriteByteToFile(uint8_t InputValue)
{
	// Сериализуем InputValue в файл
}

void WritePreferredCarTypeToFile(ECarTypes InputCarType)
{
	// Перечисление неявно преобразуется в uint8_t из-за ранее объявленного
	// типа перечисления.
	WriteByteToFile(InputCarType);
}

// С другой стороны, чтобы избежать случайного приведения к целочисленному типу или
// другому перечислению, вы можете создать класс перечисления, который не будет
// преобразовываться неявно.
enum class ECarTypes : uint8_t
{
  Sedan, // 0
  Hatchback, // 1
  SUV = 254, // 254
  Hybrid // 255
};

void WriteByteToFile(uint8_t InputValue)
{
	// Сериализуем InputValue в файл
}

void WritePreferredCarTypeToFile(ECarTypes InputCarType)
{
	// Хотя ECarTypes имеет тип uint8_t, код не будет скомпилирован из-за того,
	// что перечисление было объявлено как класс перечисления.
	WriteByteToFile(InputCarType);
}

//////////////////////////////////////////
// Классы и объектно-ориентированное программирование
//////////////////////////////////////////

// Пример классов
#include <iostream>

// Объявление класса.
// Обычно классы объявляют в заголовочном (.h или .hpp) файле.
class Dog {
    // Переменные-члены и функции являются приватными по умолчанию.
    std::string name;
    int weight;

// Все члены после этой сроки являются открытыми
// пока "private:" или "protected:" не будет объявлено.
public:

    // Конструктор по умолчанию
    Dog();

    // Объявление функций-членов
    // Обратите внимание, мы используем std::string здесь вместо использования
    // using namespace std;
    // выше.
    // Никогда не размещайте выражение "using namespace" в заголовке.
    void setName(const std::string& dogsName);

    void setWeight(int dogsWeight);

    // Функции, которые не изменяют состояние объекта,
    // должны быть помечены как const.
    // Это позволяет вызывать их, если дана const ссылка на объект.
    // Обратите внимание, функции должны быть явно объявлены как _virtual_,
    // если вы хотите перегрузить их в производных классах.
    // Функции не являются виртуальными по умолчанию для повышения производительности.
    virtual void print() const;

    // Также функции могут быть определены внутри тела класса.
    // Функции, определенные следующим образом, автоматически встроены.
    void bark() const { std::cout << name << " barks!\n"; }

    // Наряду с конструкторами, в C++ есть деструкторы.
    // Они вызываются, когда объект удаляется или выпадает из области видимости.
    // Это активирует мощную парадигму программирования, известную как RAII
    // (смотрите ниже)
    // Деструктор должен быть виртуальным, если класс будет производным.
    // Если он не виртуальный, тогда деструктор производного класса не будет вызван,
    // если объект удален по ссылке или указателю базового класса.
    virtual ~Dog();

}; // Определение класса должно завершаться точкой с запятой.

// Функции-члены класса, как правило, реализуются в .cpp файлах.
Dog::Dog()
{
    std::cout << "A dog has been constructed\n";
}

// Объекты (такие как строки) должны передаваться по ссылке если вы будете
// изменять их, или const-ссылке если нет.
void Dog::setName(const std::string& dogsName)
{
    name = dogsName;
}

void Dog::setWeight(int dogsWeight)
{
    weight = dogsWeight;
}

// Обратите внимание, "virtual" требуется только в объявлении, не в определении.
void Dog::print() const
{
    std::cout << "Dog is " << name << " and weighs " << weight << "kg\n";
}

Dog::~Dog()
{
    std::cout << "Goodbye " << name << "\n";
}

int main() {
    Dog myDog; // Печатает "A dog has been constructed"
    myDog.setName("Barkley");
    myDog.setWeight(10);
    myDog.print(); // Печатает "Dog is Barkley and weighs 10 kg"
    return 0;
} // Печатает "Goodbye Barkley"

// Интерфейсы:

// Этот класс наследует все открытые и защищенные члены класса Dog
// так же, как и все закрытые, но не может непосредственно получить доступ к закрытым
// членам\методам без открытых или защищенных методов для этого.
class OwnedDog : public Dog {

    void setOwner(const std::string& dogsOwner);

    // Переопределяем поведение функции печати для всех OwnedDog. Смотрите
    // https://goo.gl/3kuH2x для боле общего введения, если вы не знакомы
    // с концепцией полиморфизма подтипов (включения).
    // Ключевое слово override является необязательным, но указывает, что метод
    // на самом деле перегружается в базовом классе.
    void print() const override;

private:
    std::string owner;
};

// Тем временем, в соответствующем .cpp файле:

void OwnedDog::setOwner(const std::string& dogsOwner)
{
    owner = dogsOwner;
}

void OwnedDog::print() const
{
    Dog::print(); // Вызывает функцию print в базовом классе Dog
    std::cout << "Dog is owned by " << owner << "\n";
    // Печатает "Dog is <name> and weights <weight>"
    //        "Dog is owned by <owner>"
}

//////////////////////////////////////////
// Инициализация и перегрузка операторов.
//////////////////////////////////////////

// В C++ вы можете перегрузить поведение таких операторов: +, -, *, / и др..
// Это делается путем определения функции, которая вызывается,
// когда используется оператор.

#include <iostream>
using namespace std;

class Point {
public:
    // Значения по умолчанию для переменных-членов могут быть установлены
	// следующим образом.
    double x = 0;
    double y = 0;

    // Определяем новый конструктор, который инициализирует Point со значениями
    // по умолчанию (0, 0)
    Point() { };

    // Следующий синтаксис известен как список инициализации и является верным способом
	// инициализировать значения членов класса.
    Point (double a, double b) :
        x(a),
        y(b)
    { /* Ничего не делайте, кроме инициализации значений */ }

    // Перегружаем оператор +.
    Point operator+(const Point& rhs) const;

    // Перегружаем оператор +=.
    Point& operator+=(const Point& rhs);

    // Имеет смысл добавить перегрузку операторов - и -=,
    // но для краткости мы опустим эти детали.
};

Point Point::operator+(const Point& rhs) const
{
    // Создает новую точку, которая является суммой этой точки и rhs.
    return Point(x + rhs.x, y + rhs.y);
}

Point& Point::operator+=(const Point& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

int main () {
    Point up (0,1);
    Point right (1,0);
    // Здесь происходит вызов оператора + класса Point
    // Точка "up" вызывает + (функция) с параметром "right"
    Point result = up + right;
    // Печатает "Result is upright (1,1)"
    cout << "Result is upright (" << result.x << ',' << result.y << ")\n";
    return 0;
}

/////////////////////
// Шаблоны
/////////////////////

// Шаблоны в С++, в основном, используются для обобщенного программирования, хотя
// они гораздо более мощны, чем дженерики в других языках. Они также поддерживают
// явные, частные и функциональные типы классов; на самом деле, они являются
// тьюринг-полным языком, встроенным в C++!

// Мы начнем с наиболее распространенного типа обобщенного программирования. Чтобы
// определить класс или функцию, которая принимает параметр типа:
template<class T>
class Box {
public:
    // В этом классе T может быть любого типа.
    void insert(const T&) { ... }
};

// Во время компиляции компилятор фактически генерирует копии каждого шаблона
// с замещенными параметрами, поэтому полное определение класса должно присутствовать
// при каждом вызове. Именно поэтому классы шаблонов полностью определены в
// заголовочных файлах.

// Чтобы создать экземпляр класса шаблона на стеке:
Box<int> intBox;

// и вы можете использовать его, как и ожидалось:
intBox.insert(123);

// Вы, конечно, можете использовать вложенные шаблоны:
Box<Box<int> > boxOfBox;
boxOfBox.insert(intBox);

// Вплоть до С++11, вы должны были ставить пробел между двумя символами '>', иначе '>>'
// принимался парсером, как оператор сдвига вправо.

// Иногда вы можете увидеть
//   template<typename T>
// вместо этого. В этом случае ключевые слова 'class' и 'typename' _в основном_
// взаимозаменяемыми. Для более подробной информации смотрите
//   http://en.wikipedia.org/wiki/Typename
// (да-да, это ключевое слово имеет собственную страничку на вики).

// Аналогичным образом, шаблонная функция:
template<class T>
void barkThreeTimes(const T& input)
{
    input.bark();
    input.bark();
    input.bark();
}

// Обратите внимание, что здесь ничего не указано о типе параметра. Компилятор
// будет генерировать и затем проверять на тип каждый вызов шаблона, поэтому
// данная функция работает с любым типом 'T', который имеет метод 'bark'.

Dog fluffy;
fluffy.setName("Fluffy");
barkThreeTimes(fluffy); // Печатает "Fluffy barks" три раза.

//Параметры шаблона не должны быть классами:
template<int Y>
void printMessage() {
  cout << "Learn C++ in " << Y << " minutes!" << endl;
}

// В конце концов, вы можете явно специализировать шаблоны для более эффективного
// кода. Конечно, большинство реальных случаев использования специализации
// не так тривиально, как это. Обратите внимание, вам все еще нужно явно объявить
// функцию (или класс) в качестве шаблона, даже если вы явно указали все параметры.
template<>
void printMessage<10>() {
  cout << "Learn C++ faster in only 10 minutes!" << endl;
}

printMessage<20>();  // Печатает "Learn C++ in 20 minutes!"
printMessage<10>();  // Печатает "Learn C++ faster in only 10 minutes!"


/////////////////////
// Обработка исключений
/////////////////////

// Стандартная библиотека предоставляет несколько типов исключений
// (смотрите http://en.cppreference.com/w/cpp/error/exception)
// но, в принципе, любой тип может быть брошен в качестве исключения.
#include <exception>
#include <stdexcept>

// Все исключения, брошенные в блоке _try_ могут быть пойманы в последующем блоке
// _catch_.
try {
    // Не выделяйте память в куче для исключений с помощью ключевого слова _new_.
    throw std::runtime_error("A problem occurred");
}

// Поймайте исключение по константной ссылке, если оно является объектом
catch (const std::exception& ex)
{
    std::cout << ex.what();
}

// Ловит любое исключение, не пойманное предыдущим блоком _catch_
catch (...)
{
    std::cout << "Unknown exception caught";
    throw; // Повторный выброс исключения
}

///////
// Получение ресурса есть инициализация (RAII)
///////

// Программная идиома объектно-ориентированного программирования, смысл которой
// заключается в том, что с помощью тех или иных программных механизмов получение
// некоторого ресурса неразрывно совмещается с инициализацией, а освобождение -
// с уничтожением объекта.

// Чтобы понять, на сколько это полезно,
// рассмотрим функцию, которая использует обработчик файлов в С:
void doSomethingWithAFile(const char* filename)
{
    // Для начала, предположим, ничего не может потерпеть неудачу.

    FILE* fh = fopen(filename, "r"); // Открываем файл в режиме чтения.

    doSomethingWithTheFile(fh);
    doSomethingElseWithIt(fh);

    fclose(fh); // Закрываем обработчик файла.
}

// К сожалению, вещи быстро осложняются обработкой ошибок.
// Предположим, fopen может потерпеть неудачу, тогда doSomethingWithTheFile и
// doSomethingElseWithIt вернут коды ошибок, если потерпят неудачу.
//  (Исключения являются предпочтительным способом обработки ошибок,
//   но некоторые программисты, особенно те, кто имеет большой опыт работы с С,
//   не согласны с аргументами о полезности исключений).
// Теперь мы должны проверить каждый вызов на наличие ошибок и закрыть обработчик
// файла, если он есть.
bool doSomethingWithAFile(const char* filename)
{
    FILE* fh = fopen(filename, "r"); // Открывает файл в режиме чтения
    if (fh == nullptr) // В случае неудачи возвращаемый указатель принимает значение null.
        return false; // Сообщает о неудаче вызывающему.

    // Предположим, каждая функция возвращает false в случае неудачи
    if (!doSomethingWithTheFile(fh)) {
        fclose(fh); // Закрываем обработчик файла, чтобы не было утечек
        return false; // Сообщает об ошибке.
    }
    if (!doSomethingElseWithIt(fh)) {
        fclose(fh); // Закрываем обработчик файла, чтобы не было утечек
        return false; // Сообщает об ошибке.
    }

    fclose(fh); // Закрываем обработчик файла, чтобы не было утечек
    return true; // Указывает на успех
}

// C-программисты часто упорядочивают это с помощью goto:
bool doSomethingWithAFile(const char* filename)
{
    FILE* fh = fopen(filename, "r");
    if (fh == nullptr)
        return false;

    if (!doSomethingWithTheFile(fh))
        goto failure;

    if (!doSomethingElseWithIt(fh))
        goto failure;

    fclose(fh); // Закрываем файл.
    return true; // Указывает на успех

failure:
    fclose(fh);
    return false; // Сообщает об ошибке.
}

// Если функции указывают на ошибки с помощью исключений, вещи становятся проще,
// но все еще не оптимальны.
void doSomethingWithAFile(const char* filename)
{
    FILE* fh = fopen(filename, "r"); // Открываем файл в режиме чтения
    if (fh == nullptr)
        throw std::runtime_error("Could not open the file.");

    try {
        doSomethingWithTheFile(fh);
        doSomethingElseWithIt(fh);
    }
    catch (...) {
        fclose(fh); // Убедитесь, что закрываете файл, если происходит ошибка.
        throw; // Затем повторно бросает исключение.
    }

    fclose(fh); // Закрываем файл.
    // Успех
}

// Сравните это с использованием класса потока файла (fstream) в С++, который
// использует свой деструктор, чтобы закрыть файл. Еще раз взгляните выше,
// деструктор вызывается автоматически, когда объект выпадает из области видимости.
void doSomethingWithAFile(const std::string& filename)
{
    // ifstream определяет файловый поток
    std::ifstream fh(filename); // Открыть файл

    // Что-то делать с файлом
    doSomethingWithTheFile(fh);
    doSomethingElseWithIt(fh);

} // Здесь файл автоматически закрывается в деструкторе.

// Это имеет _огромнейшие_ преимущества:
// 1. Неважно, что произойдет,
//    ресурсы (в данном случае дескриптор файла) будут очищены.
//    После того, как вы правильно напишете деструктор,
//    Больше будет _невозможно_ закрыть обработчик файлов или допустить утечку.
// 2. Обратите внимание, что код намного проще.
//    Деструктор закрывает файловый поток "за кулисами", и вам больше не нужно об
//     этом беспокоиться.
// 3. Код устойчив к исключениям.
//    Исключение может быть брошено в любом месте в функции, и это никак не повлияет
//    на очистку.

// Весь идиоматический код на С++ широко использует RAII для всех ресурсов.
// Дополнительные примеры включат:
// - Использование памяти unique_ptr и shared_ptr
// - Контейнеры - стандартная библиотека связанных списков, векторы
//   (т.е. самоизменяемые массивы), хэш-таблицы и все остальное автоматически
//    уничтожается сразу же, когда выходит за пределы области видимости.
// - Ипользование мьютексов lock_guard и unique_lock

// Контейнеры с пользовательскими классами в качестве ключей требуют
// сравнивающих функций в самом объекте или как указатель на функцию. Примитивы
// имеют компараторы по умолчанию, но вы можете перегрузить их.
class Foo {
public:
	int j;
	Foo(int a) : j(a) {}
};
struct compareFunction {
    bool operator()(const Foo& a, const Foo& b) const {
        return a.j < b.j;
    }
};
// это не допускается (хотя это может варьироваться в зависимости от компилятора)
// std::map<Foo, int> fooMap;
std::map<Foo, int, compareFunction> fooMap;
fooMap[Foo(1)]  = 1;
fooMap.find(Foo(1)); //true

/////////////////////
// Веселые вещи
/////////////////////

// Аспекты С++, которые могут быть удивительными для новичков (и даже для некоторых
// ветеранов). Этот раздел, к сожалению, очень неполон. С++ является одним из самых
// простых языков, где очень легко выстрелить себе в ногу.

// Вы можете перегрузить приватные методы!
class Foo {
  virtual void bar();
};
class FooSub : public Foo {
  virtual void bar();  // Перегружает Foo::bar!
};


// 0 == false == NULL (в основном)!
bool* pt = new bool;
*pt = 0; // Устанавливает значение указателя 'pt' в false.
pt = 0;  // Устанавливает значение 'pt' в нулевой указатель. Обе строки проходят
		// компиляцию без ошибок.

// nullptr приходит на помощь:
int* pt2 = new int;
*pt2 = nullptr; // Не пройдет компиляцию
pt2 = nullptr;  // Устанавливает pt2 в null.

// Существует исключение для булевых значений.
// Это позволит вам проверить указатели с помощью if(!ptr),
// но как следствие вы можете установить nullptr в bool напрямую!
*pt = nullptr;  // Это по прежнему проходит компиляцию, даже если '*pt' - bool!


// '=' != '=' != '='!
// Вызывает Foo::Foo(const Foo&) или некий вариант (смотрите "move semantics")
// конструктора копирования.
Foo f2;
Foo f1 = f2;

// Вызывает Foo::Foo(const Foo&) или вариант, но копирует только часть 'Foo' из
// 'fooSub'. Любые другие члены 'fooSub' пропускаются. Иногда это ужасное поведение
// называют "object slicing."
FooSub fooSub;
Foo f1 = fooSub;

// Вызывает Foo::operator=(Foo&) или вариант.
Foo f1;
f1 = f2;


// Как по-настоящему очистить контейнер:
class Foo { ... };
vector<Foo> v;
for (int i = 0; i < 10; ++i)
  v.push_back(Foo());

// В следующей точке размер v устанавливается в 0, но деструктор не вызывается
// и не происходит очистка ресурсов!
v.empty();
v.push_back(Foo());  // Новые значения копируются в первый вставленный Foo

// Настоящее уничтожение всех значений v. Смотрите раздел о временном объекте
// для объяснения того, как это работает.
v.swap(vector<Foo>());


