#include "Graph.h" // Подключаем заголовочный файл "Graph.h"

namespace graph
{
	// Конструктор для создания пустой матрицы смежности заданного размера
	AMatrix::AMatrix(int n)
	{
		this->n_vertex = n; // Устанавливаем количество вершин
		this->mr = new int[this->n_vertex * this->n_vertex]; // Выделяем память для матрицы
		for (int i = 0; i < n * n; i++) mr[i] = 0; // Инициализируем матрицу нулями
	}

	// Конструктор для создания матрицы смежности из переданного массива mr
	AMatrix::AMatrix(int n, int mr[])
	{
		this->n_vertex = n; // Устанавливаем количество вершин
		this->mr = mr; // Используем переданный массив
	}

	// Конструктор копирования для создания матрицы смежности на основе другой матрицы am
	AMatrix::AMatrix(const AMatrix& am)
	{
		this->n_vertex = am.n_vertex; // Устанавливаем количество вершин
		this->mr = new int[this->n_vertex * this->n_vertex]; // Выделяем память для новой матрицы
		for (int i = 0; i < this->n_vertex; i++)
			for (int j = 0; j < this->n_vertex; j++)
				this->set(i, j, am.get(i, j)); // Копируем элементы из матрицы am
	}

	// Конструктор для создания списка смежности из переданного списка
	AMatrix::AMatrix(const AList& al)
	{
		this->n_vertex = al.n_vertex; // Устанавливаем количество вершин
		this->mr = new int[this->n_vertex * this->n_vertex]; // Выделяем память для матрицы
		for (int k = 0; k < this->n_vertex * this->n_vertex; k++) mr[k] = 0; // Инициализируем матрицу нулями
		for (int i = 0; i < this->n_vertex; i++)
			for (int j = 0; j < al.size(i); j++) this->set(i, al.get(i, j), 1); // Заполняем матрицу из списка
	}

	// Метод для установки значения в ячейку (i, j) матрицы
	void AMatrix::set(int i, int j, int r)
	{
		this->mr[i * this->n_vertex + j] = r; // Устанавливаем значение в соответствующую ячейку
	}

	// Метод для получения значения из ячейки (i, j) матрицы
	int AMatrix::get(int i, int j) const
	{
		return this->mr[i * this->n_vertex + j]; // Возвращаем значение из соответствующей ячейки
	}

	// Метод для создания пустого списка смежности заданного размера
	void AList::create(int n)
	{
		this->mr = new std::list<int>[this->n_vertex = n]; // Выделяем память для массива списков
	}

	// Конструктор для создания пустого списка смежности заданного размера
	AList::AList(int n)
	{
		create(n); // Создаем список смежности
	}

	// Конструктор для создания списка смежности из матрицы смежности am
	AList::AList(const AMatrix& am)
	{
		create(am.n_vertex); // Создаем список смежности заданного размера
		for (int i = 0; i < this->n_vertex; i++)
			for (int j = 0; j < this->n_vertex; j++)
				if (am.get(i, j) != 0) this->add(i, j); // Добавляем ребра в список из ненулевых элементов матрицы
	}

	// Конструктор копирования для создания списка смежности на основе другого списка al
	AList::AList(const AList& al)
	{
		create(al.n_vertex); // Создаем список смежности заданного размера
		for (int i = 0; i < this->n_vertex; i++)
			for (int j = 0; j < al.size(i); j++) this->add(i, al.get(i, j)); // Добавляем ребра из списка al
	}

	// Конструктор для создания списка смежности из переданного массива mr
	AList::AList(int n, int mr[])
	{
		create(n); // Создаем список смежности заданного размера
		for (int i = 0; i < this->n_vertex; i++)
			for (int j = 0; j < this->n_vertex; j++)
				if (mr[i * this->n_vertex + j] != 0) this->add(i, j); // Добавляем ребра из ненулевых элементов массива
	}

	// Метод для добавления ребра из вершины i в вершину j в список смежности
	void AList::add(int i, int j)
	{
		this->mr[i].push_back(j); // Добавляем вершину j в список вершины i
	}

	// Метод для получения количества смежных вершин для вершины i
	int AList::size(int i) const
	{
		return (int)this->mr[i].size(); // Возвращаем размер списка смежности для вершины i
	}

	// Метод для получения j-ой смежной вершины для вершины i
	int AList::get(int i, int j) const
	{
		std::list<int>::iterator rc = this->mr[i].begin(); // Итератор для списка вершины i
		for (int k = 0; k < j; k++) rc++; // Перемещаем итератор до нужной позиции
		return (int)*rc; // Возвращаем значение на позиции j
	}
}
