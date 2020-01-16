#include <iostream>
#include <clocale>

using namespace std;

struct Node
{
	int d;
	Node* next;
	Node* prev;
};

void add(Node*& begin, int d);
Node* find(Node* begin, int i);
bool insert(Node* begin, int key, int d);
void print(Node* begin);
bool remove(Node* begin, int key);

int main()
{
	int v;
	int n, g, a, b, d;
	setlocale(LC_ALL, "Russian");
	Node* begin = nullptr;

	int e;

	do
	{
		cout << "Выберите номер действия, которое хотите выполнить:" << endl;
		cout << "1. Вывести однонаправленный список" << endl;
		cout << "2. Добавить элементы в конец списка" << endl;
		cout << "3. Удалить элемент из списка" << endl;
		cout << "4. Вставить элемент после заданного" << endl;
		cout << "5. Выход." << endl;

		while (!(cin >> e) || (cin.peek() != '\n'))
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Некоректные данные, попробуйте снова" << endl;
		}

		switch (e)
		{
		case 1:
		{
			print(begin);
			cout << endl;
			system("pause");
			system("cls");
		};
		break;

		case 2:
		{
			print(begin);
			cout << endl;
			cout << "Введите количество элементов: ";
			while (!(cin >> v) || (cin.peek() != '\n'))
			{
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Некоректные данные, попробуйте снова" << endl;
			}
			for (int i = 1; i < v + 1; i++)
				add(begin, i);
			cout << endl;
			print(begin);
			cout << endl << endl;
			system("pause");
			system("cls");
		}
		break;

		case 3:
		{
			cout << "Введите элемент, которое хотите удалить: ";
			while (!(cin >> n) || (cin.peek() != '\n'))
			{
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Некоректные данные, попробуйте снова" << endl;
			}
			cout << endl;
			if (!remove(begin, n))cout << "Удаление не выполнено " << endl;
			print(begin);
			cout << endl;
			system("pause");
			system("cls");
		};
		break;

		case 4:
		{
			cout << "Введите число, после которого нужно добавить элемент: ";
			while (!(cin >> a) || (cin.peek() != '\n'))
			{
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Некоректные данные, попробуйте снова" << endl;
			}
			cout << "Введите элемент, которое хотите добавить: ";
			while (!(cin >> b) || (cin.peek() != '\n'))
			{
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Некоректные данные, попробуйте снова" << endl;
			}
			insert(begin, a, b);
			print(begin);
			cout << endl;
			system("pause");
			system("cls");
		};
		break;

		case 5:
		{
			system("pause");
			return 0;
		}
		default:
		{
			cout << "Нужно ввести число от 1 до 5 " << endl;
			system("pause");
			system("cls");
		}
		break;
		}

	}



	while (e != 5);
	system("Pause");
	return 0;
}

//добавление элемента в конец списка 

void add(Node*& begin, int d)
{
	Node* cur = new Node;
	cur->d = d;
	cur->next = nullptr;
	if (!begin) { begin = cur; cur->prev = nullptr; }
	else
	{
		Node* temp = begin;
		while (temp->next)

			temp = temp->next;
		temp->next = cur;
		cur->prev = temp;


	}
}

//поиск элемента по ключу 

Node* find(Node* begin, int d)
{
	Node* cur = begin;
	while (cur) {
		if (cur->d == d)break;
		cur = cur->next;
	}
	return cur;
}

//вставка элемента после заданного элемента

bool insert(Node* begin, int key, int d) {
	Node* pkey = find(begin, key);
	if (!pkey) return false;
	Node* cur = new Node;
	cur->d = d;
	cur->next = pkey->next;
	cur->prev = pkey;
	pkey->next = cur;
	if (cur->next != nullptr) (cur->next)->prev = cur;
	return true;
}

//вывод списка на экран 

void print(Node* begin)
{
	Node* cur = begin;
	while (cur)
	{
		cout << cur->d << ' ';
		cur = cur->next;

	}
}

//удаление заданного элемента 

bool remove(Node* begin, int key)
{
	Node* cur = find(begin, key);
	if (!cur)return false;
	if (cur == begin) {
		begin = begin->next;
		begin->prev = nullptr;
	}
	else
	{
		(cur->prev)->next = cur->next;
		if (cur->next != nullptr)(cur->next)->prev = cur->prev;
	}
	delete cur;
	return true;
}