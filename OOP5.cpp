#include<iostream>
#include<string.h>
using namespace std;
class Dep {
private:
	 double sum;
	 char* name;
	 int n;
public:
	 Dep() :sum(), name() {};
	 Dep(double h, char* names) {
		  sum = h;
		  name = names;
	 }
	 Dep(const Dep&obj) {
		  sum = obj.sum;
		  name = obj.name;
	 }
	 ~Dep() {}
	virtual void SetSum(double a) {
		  sum = a;
	 }
	 void SetName(char* names) {
		  name = names;
	 }
	virtual double GetSum() { return sum; }
	virtual char* GetName() { return name; }
};
class Bank :public Dep {
private:
	 int termin;
	 double rich;
public:
	 Bank() :Dep() {};
	 Bank(double a, char* names, int ter, double rik) {
		  SetSum(a);
		  SetName(names);
		  termin = ter;
		  rich = rik;
	 }
	 ~Bank() {}
	 virtual double Vids() {
		  double Vids;
		  Vids = termin * rich*GetSum();
		  return Vids;
	 }
	  void Print() {
		  cout <<"Ім'я:"<<GetName()<<endl;
		  cout << "Сума вкладу:" << GetSum()<<endl;
		  cout << "Сума:" << Vids() << endl;
		  }
};
class Bank2 :public Dep {
private:
	 int termin;
	 double *Massyv;
	 int n;
public:
	 Bank2() :Dep() {};
	 Bank2(double a, char *names, int ter) {
		  SetSum(a);
		  SetName(names);
		  termin = ter;
		  n = int((ter / 4));
		  Massyv = new double[n];
		  for (int i = 0; i < n; i++) {
				cout<<"Введіть "<< i+1 <<" квартал:";
				cin >> Massyv[i];

		  }
	 }
	 ~Bank2() { }
	 double Vids() {
		  double Vids;
		  double k = 0;
		  for (int i = 0; i < n; i++) {
				k = k + ((GetSum()*(Massyv[i] / 100)) / 4);
		  }
		  return GetSum()+k;
	 }
	 void Print() {
		  cout << "Ім'я:" << GetName() << endl;
		  cout << "Сума вкладу:" << GetSum() << endl;
		  cout << "Сума:" << Vids() << endl;
		  for (int i = 0; i < n; i++) {
				cout <<"Квартальна ставка:\n"<<Massyv[i]<<endl;
		  }
	 }
};
bool operator>(Bank&obj, Bank&obj1) {
	 return (obj.Vids() > obj1.Vids());

};
int main() {
	 system("chcp 1251");
	 int n, d, l;
	 cout << "\n Введіть кількість рахунків(відсоткова ставка):";
	 cin >> n;
	 getchar();
	 Bank *p = new Bank[n];
	 cout << "Введіть  дані\n";
	 for (int i = 0; i < n; i++) {
		  char name[100][100];
		  int ter;
		  double rich, suma;
		  cout << "\n Ім'я:" << endl;
		  gets_s(name[i], 100);
		  cout << "Сума депозиту:" << endl;
		  scanf_s("%lf", &suma);
		  cout << "Термін:" << endl;
		  scanf_s("%d", &ter);
		  cout << "Річна ставка:" << endl;
		  scanf_s("%lf", &rich);
		  getchar();
		  p[i] = Bank(suma, name[i], ter, rich);
	 }
	 for (int i = 0; i < n; i++) {
		  l = 1;
		  Bank copy;
		  if ((i + 1) == n)
				break;
		  for (; (i + l) < n; l++) {
				if ((p[i] > p[i + l]) == 0) {
					 copy = p[i];
					 p[i] = p[i + l];
					 p[i + l] = copy;
					 i = -1;
					 l = n;
				}
		  }
	 }
	 cout << "\n Введіть кількість рахунків(поквартальна ставка):";
	 cin >> d;
	 Bank2*m = new Bank2[d];
	 for (int i = 0; i < d; i++) {
		  char name[100][100];
		  int term;
		  double sum;
		  getchar();
		  cout << "\n Ім'я:" << endl;
		  gets_s(name[i], 100);
		  cout << "Сума депозиту:" << endl;
		  scanf_s("%lf", &sum);
		  cout << "Термін:" << endl;
		  scanf_s("%d", &term);
		  m[i] = Bank2(sum, name[i], term);
	 }
	 for (int i = 0; i < d; i++) {
		  l = 1;
		  Bank copy;
		  if ((i + 1) == d)
				break;
		  for (; (i + l) < d; l++) {
				if ((p[i] > p[i + l]) == 0) {
					 copy = p[i];
					 p[i] = p[i + l];
					 p[i + l] = copy;
					 i = -1;
					 l = d;
				}
		  }
	 }
	 cout << "\n Відсортований список:";
	 cout << "\n Відсоткова ставка:"<<endl;
	 for (int i = 0; i < n; i++) {
		  p[i].Print();
	 }
	 cout << "\n Поквартальна ставка:"<<endl;
	 for (int i = 0; i < d; i++) {
		  m[i].Print();
	 }
}
	 
		  