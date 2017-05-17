# Lib

!Это не попытка написать документацию - это краткое описание интерфеса(отсюда думаю понятно что здесть ТОЛЬКО методы)!

# libalgorithm.h
// Две шаблонные функции доступа по индексу и удаления по индексу. Используют итераторы. И метод remove(iter);

# Graph(Не дописаны алгоритмы!)
  Ориентированный граф, с представлением в виде списка списков.
  
  ### Стандартные методы добавления и удаления вершин и ребер:
		* void addVertex(const N& value);
		* void addEdge(const N source, N dest,const W& weight);
    * void removeVertex(const N& value);
    * void removeEdge(const N source, N dest);


# List
  Обычный двусвязный список.
  
 ### Итераторы:
 
		* typedef ListIterator<T> iterator;
		* typedef ConstListIterator<T> const_iterator;
		* typedef ReverseListIterator<T> reverse_iterator;
    
 ### Мутоды для работы с итераторами:
 
    * ListIterator<T> begin() const;
		* ListIterator<T> end() const;
		* const ConstListIterator<T> cBegin() const;
		* const ConstListIterator<T> cEnd() const;
		* ReverseListIterator<T> rBegin() const;
		* ReverseListIterator<T> rEnd() const;
  
 ### Добавление и снаятие с начал/конца, удаление:
 
    * void push_back(const T&);
		* void push_front(const T&);
		* void pop_back();
		* void pop_front();
		* void remove(ListIterator<T>&);

 ### Последний и первый эллемент:
 
    * const T& back() const;
		* const T& front() const;
    
 ### Вспомогательные функции:
 
    * size_t size() const;
		* bool isEmpty() const;


# AvlTree
  Сбалансированное АВЛ-Дерево. В большинстве, public-методы служат только оболочкой для private-методов.
  
 ### Исключения: 
 
      * NOT_FOUND,
      * SMTH_ELSE	// TODO?
  
 ### Итераторы:
 
		* typedef AvlTreeIterator<K, V> iterator;
    // ReverseAvlTreeIterator<K, V> работает, но не подключен тайпдефом.
    
 ### Методы для работы с итераторами:
 
    * AvlTreeIterator<K, V> begin() const;
		* AvlTreeIterator<K, V> end() const;
		* ReverseAvlTreeIterator<K, V> rBegin() const;
		* ReverseAvlTreeIterator<K, V> rEnd() const;

 ### Стандартные для дерева методы:
 
    * void insert(const K& key, const V& value);
		* void remove(const K& key);
		* void remove(AvlTreeIterator<K, V>& iter);
		* void clear();
		* V& find(const K& key);
    
 ### Вспомогательные функции:
 
    * TreeNode<K, V>* getMin(TreeNode<K, V>* node) const;
		* TreeNode<K, V>* getMax(TreeNode<K, V>* node) const;
		* size_t size() const;

