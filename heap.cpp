#include <cstdio>
#include <iostream>
#define inf 2147483647
using namespace std;
class heap
{
public:
	void insert(int p);
	void heapsort();
	void show();
	void pop();
private:
	int size;
	int a[10001];
	void adjust(int i,int n);
	void shiftup(int i);
};

void swap(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
void heap::adjust(int i,int n)
{
	if (i * 2 <= n)
		if (a[i] < a[i * 2])
		{
			swap(a[i], a[i * 2]);
			adjust(i * 2,n);
		}
	if (i * 2 + 1 <= n)
		if (a[i] < a[i * 2 + 1])
		{
			swap(a[i], a[i * 2 + 1]);
			adjust(i * 2 + 1,n);
		}
}

void heap::heapsort()
{
	for (int i = size; i > 1; i--)
	{
		swap(a[1], a[i]);
		adjust(1, i - 1);
	}
}
void heap::shiftup(int i)
{
	if (i >= 1)
	{
		if (a[i / 2] < a[i])
			swap(a[i / 2], a[i]);
		shiftup(i / 2);
	}
}
void heap::insert(int p)
{
	
	a[++size] = inf;
	shiftup(size);
	a[1] = p;
	adjust(1,size);
}
void heap::show()
{
	cout<<"num:"<<size<<endl;
	for (int i = 1; i <= size; i++)
		cout << a[i] << " ";
}
void heap::pop(){
	swap(a[1], a[size]);
		adjust(1, size - 1);
	size--;
}
int main()
{
	int n;
	heap h;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		h.insert(tmp);
	}
	//build(n);
	h.pop();
	h.show();
	h.heapsort();
	h.show();
	return 0;
}
//1 3 4 5 7 2 6 8 0