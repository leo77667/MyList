

#include<iostream>
using namespace std;

template<class T>
class MyList{
private:
	T *a;
	int size;
	int n;
	void double_space(){
		T *b; int i;
		size = size*2;
		b = new T [size];
		for(i = 0; i < n; ++i)
			b[i] = a[i];
		delete [] a;
		a = b;
	}		                                                   
public:

	
	MyList(){
		size = 100;
		a = new T [size];
		n = 0;
	}
	MyList(int num, const T &item);
	MyList(const MyList &l);
    MyList(T* arr, int len);

	void push(const T &item);
	T pop();
	void insert(int index, const T &item);
	void clean();
	int get_size();
	int get_SIZE();
	void erase(int start, int end);
	T get_item(int index);
	MyList get_item(int start, int end) ;
	int count(const T &item);
	void remove(const T &item);

	
	friend MyList operator + (const MyList &l1, const MyList &l2){
		MyList<T> tmp; int i;
		tmp.n = l1.n + l2.n;
		int t = tmp.get_SIZE();
		while(t < tmp.n)	
			tmp.double_space();
		for (i = 0; i < l1.n; ++i)
			tmp[i] = l1[i];
		for (i = 0; i < l2.n; ++i)
			tmp[i+l1.n] = l2[i];
		return tmp;	
	}
    friend MyList<T> operator + (const MyList<T> &l1, const T &item){
		MyList<T> tmp;
		tmp.n = l1.n + 1;
		int t = tmp.get_SIZE();
		while( t < tmp.n)	
			tmp.double_space();
		tmp[l1.n] = item;
		return tmp;
	} 
	MyList &operator = (const MyList &l);
	MyList &operator += (const T &item);
	MyList &operator += (const MyList &l);
	T &operator [](const int index) const;
	
	friend ostream & operator<<(ostream &os, const MyList<T> &obj){
		int i;
		os << '[' ;
		if (obj.n == 0){
			os << ']';
			return os;
		}
		for (i = 0; i < obj.n-1; ++i)
			os << obj[i] << ',' <<' ';
		os << obj[obj.n-1] << ']';
		return os;
		}

	void sort(bool);
    
	void reverse();

	~MyList(){delete [] a;} 
};
  
template <class T>
MyList<T>::MyList(int num, const T &item){
	int i;
	size = num;
	a = new T [size];
	for (i = 0; i < num; ++i)
		a[i] = item;
	n = num;
}

template <class T>
MyList<T>::MyList(const MyList &l){
	int i;
	size = l.size;
	a = new T [size];
	for (i = 0; i < n; ++i)
		a[i] = l.a[i];
	n = l.n;	
}

template <class T>
MyList<T>:: MyList(T* arr, int len){
	int i;
	size = len;
	a = new T [size];
	for (i = 0; i < len; ++i)
		a[i] = arr[i];
	n = len;
}

template <class T>
void MyList<T>::push(const T &item){
	if (size = n)
		double_space();
	a[n] = item;
	++n;
}

template <class T>
T MyList<T>:: pop(){
	try{
	if (n == 0) throw 0;
	--n;
	return a[n];
	}
	catch(int ){
		cout << "Can not pop an empty list"<< endl;
	}
}

template <class T>
void MyList<T>::insert(int index, const T &item){
	int i; T *b;
	if (size = n)
		size = size*2;
	b = new T [size];
	try{
	if (index > n)
	throw 2;
	for (i = 0; i < index; ++i)
		b[i] = a[i];
	b[index] = item;
	for (i = index+1; i < n+1; ++i)
		b[i] = a[i-1];
	delete [] a;
	a = b;
	++n;
    } 
    catch(int){
    	cout << "List index out of range" << endl;
    	
	}
}

template <class T>
void MyList<T>::clean(){
	n = 0;
}

template <class T>
int MyList<T>::get_size(){
	return n;
}

template <class T>
int MyList<T>::get_SIZE(){
	return size;
}

template <class T>
void MyList<T>::erase(int start, int end){
	int i; T *b;
	b = new T [size];
	try{
	if (start > n || end > n || start < 0 || end < 0)
	throw 1;
	for (i = 0; i < start; ++i)
		b[i] = a[i];
	for (i = end+1; i < n; ++i) 
		b[i-(end-start)-1] = a[i];
	delete [] a;
	a = b;
	n = n - (end - start)-1;
	}
	catch(int){
		cout << "List index out of range" << endl;
		
	}
}

template <class T>
T MyList<T>::get_item(int index){
	try{
	if (index < 0 || index > n)
		throw 4; 
	return a[index];
    } 
    catch (int) {
    	cout <<  "List index out of range" << endl;
    	return 0;
	}
}

template <class T>
MyList<T> MyList<T>:: get_item(int start, int end) {
	MyList<T> b;
	try{
	if (start < 0)
		start = n + start;
	if (end < 0)
		end = n + end;
	if (start > end)
		return b;
	if (start > n || end > n || start < 0 || end < 0)
		throw 1;
	int i;
	b.n = end - start + 1;
	while (size < b.n)
		b.double_space();
	for (i = start; i <= end; ++i )
		b.a[i-start] = a[i];
	return b;
	}
	catch(int){
		cout << "List index out of range" << endl;
	}
}

template <class T>
int MyList<T>:: count(const T &item){
	int i, num = 0;
	for (i = 0; i < n; ++i)
		if (a[i] == item)
			++num;
	return num;
}

template <class T>
void MyList<T>:: remove(const T &item){
	int i;
	for (i = 0; i < n; ++i)
		if (a[i] == item){
			erase(i,i);
			break;
}
}




template <class T>
MyList<T> &MyList<T>::operator = (const MyList &l){
	int i;
	n = l.n;
	while (size < n)
		double_space();
	for (i = 0; i < l.n; ++i)
		a[i] = l.a[i];
	return *this;
}

template <class T>
MyList<T> &MyList<T>::operator += (const T &item){
	int i;
	n = n + 1;
	while(size < n)
		double_space();
	a[n-1] = item;
	return *this;
}

template <class T>
MyList<T> &MyList<T>::operator += (const MyList &l){
	int i;
	while(size < n)
		double_space();
	for (i = 0; i < l.n; ++i)
		a[i + n] = l.a[i];
	n = n + l.n;
	return *this;
}

template <class T>
T &MyList<T>::operator [](int index) const{
	try{
	if (index < 0 || index > n)
	throw 5;
	return a[index];
	}
	catch (int){
		cout << "List index out of range" << endl;
	}
}


template <class T>
void quickSort(T s[], int l, int r)  
{   
    if (l< r)  
    {        
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j]>= x)
                j--;   
            if(i < j)  
                s[i++] = s[j];  
            while(i < j && s[i]< x)
                i++;   
            if(i < j)  
                s[j--] = s[i];
        }  
        s[i] = x;  
        quickSort(s, l, i - 1);
        quickSort(s, i + 1, r);  
    }  
}  


template <class T>
void MyList<T>::sort(bool less=true){
	int k;  
    int len=n;   
    quickSort(a,0,len-1); 
	if (!less)
	reverse();	
}
 
template <class T>
void MyList<T>::reverse(){
	int i; T *b;
	b = new T [n];
	for (i = 0; i < n; ++i)
		b[n-1-i] = a[i];
	delete [] a;
	a = b;
}
int main(){ 
	MyList<int> a, b;
	int i;
	for (i=0; i<5; ++i)
		a.push(i);
    // a = [0, 1, 2, 3, 4]
	a[3] = 15; // a = [0, 1, 2, 15, 4]
	a.sort(); // a = [0, 1, 2, 4, 15]
	a.reverse(); // a = [15, 4, 2, 1, 0]
	a += 12; // a = [15, 4, 2, 1, 0, 12]
	for (i=0; i<a.get_size(); ++i)
		cout<<a[i]<<endl;
    b = a.get_item(4, -3); // b = [] 
	b = a.get_item(3, -1); // b = [1, 0, 12] 
	cout << b; 
	a += b; // a = [15, 4, 2, 1, 0, 12, 1, 0, 12]
	for (i=0; i<a.get_size(); ++i)
		cout<<a.get_item(i)<<endl;
	cout<<a.count(5)<<endl;
	b.clean(); // b = []
	cout<<b.get_size()<<endl;
	a.erase(2, 5); // a = [15, 4, 0, 12]
	b = a + a; // b = [15, 4, 1, 0, 12, 15, 4, 1, 0, 12]
	b.insert(3, 116); // b = [15, 4, 1, 116, 0, 12, 15, 4, 1, 0, 12]
	b.remove(4); // b = [15, 1, 116, ...]
	cout<<b<<endl;
	MyList<double> c(10, 3.14);
	for (i=0; i<100; ++i)
		c.push(1.1*i);
	cout<<c.get_item(100, 105)<<endl;
	return 0;
}  

 


