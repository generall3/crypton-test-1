#include <iostream>
#include <fstream>
#include <string>

// структура пользователей
struct Users
{
  char name[64]; // имя пользователя
  int reqnum; // количество запросов в час
  int timenum; // количество часов
  char data[64]; // дополнительная информация
  int reqsum; // общая сумма запросов

};


// вывод информации
void show(Users *M,int N)
{
  std::ofstream outfile("/home/user/Documents/github/crypton.studio-test/parser/file2.txt", std::ios_base::in); // файл для вывода данных
  for (int i=0;i<N;i++)
  {
    outfile << M[i].name;
    outfile << M[i].reqnum;
    outfile << M[i].timenum;
    outfile << M[i].data;
  }
  outfile << std::endl;
}
// занесение данных в структуру
void get(Users *M,int N)
{
  std::ifstream infile("/home/user/Documents/github/crypton.studio-test/parser/file1.txt", std::ios_base::in); // файл для чтения данных
  infile.ignore();
     for (int i=0;i<N;i++)
      {
        infile.getline(M[i].name,64); // считывание из файла имени пользователя
        infile.ignore();

        infile >> M[i].reqnum; // считывание из файла количества запросов в час
        infile.ignore();

        infile >> M[i].timenum; // считывание из файла количества часов
        infile.ignore();

        infile.getline(M[i].data,64); // считывание из файла дополнительной информации
        infile.ignore();
      }
}

int numberofstrings()
{
    std::string line;
    int strnum = 0;
    std::ifstream in("/home/user/Documents/github/crypton.studio-test/parser/file1.txt"); // файл для чтения данных
    if (in.is_open())
    {
        while (getline(in, line))
        {
            strnum++;
        }
    }
    return strnum;
    in.close();
}

/*ГЛАВНАЯ ФУНКЦИЯ*/
int main()
{
    int N = numberofstrings();
    Users *M = new Users[N];
    get(M,N);               //Ввод данных в массив структур
    show(M,N);              //Вывод массива структур на экран
    delete []M;

    return 0;
}
