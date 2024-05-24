
#include <iostream>
#include <string>
#include <initializer_list>
#include "../header/spreadsheet.h"


int main()
{
    SpreadSheet sp1 = SpreadSheet(3, 4); 
    std::cout << sp1; 
    sp1[0][2] = 5.4;
    std::cout << sp1; 
    sp1[0][0] = std::string("magnolia");
    std::cout << sp1; 
   
    SpreadSheet sp2 = sp1;
    std::cout << sp2;


    sp1.resizeRow(5);
    std::cout << sp1.row() << std::endl;
    sp1.resizeCol(2);
    std::cout << sp1; 
    sp1.resizeCol(4);
    std::cout << sp1.col() << std::endl << sp1;

    sp1.resize(2, 2);
    std::cout << sp1;//:ok

    sp1.removeCol(0);
    std::cout << sp1;

    sp2.removeRow(0);
    std::cout << sp2; 

    std::cout << "_________________\n";

    std::vector<int> v = {1, 2, 3, 4, 5};
    Cell cell = v;

    std::cout << cell << std::endl; 

    v.push_back(100);
    std::cout << v << std::endl; 
    v = static_cast<std::vector<int>>(cell);
    std::cout << v << std::endl;
    const Cell cell2 = v;
    std::cout << (cell2 == cell) << (cell != cell2) << std::endl;// 10 : OK


    std::cout << std::endl << "Mirrors" << std::endl << std::endl;
    SpreadSheet test = {3,4};
    int c = 1;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            test[i][j] = c++;
        }
    }
    std::cout << test;
    SpreadSheet tmp = test;
    tmp.mirrorH();
    std::cout << tmp;
    std::cout << std::endl;
    tmp = test;
    tmp.rotate(1);
    std::cout << tmp;
    std::cout << std::endl;
    tmp = test;
    tmp.rotate(2);
    std::cout << tmp;
    std::cout << std::endl;
    tmp = test;
    tmp.rotate(3);
    std::cout << tmp;
    std::cout << std::endl;
    tmp = test;
    tmp.mirrorD();
    std::cout << tmp;
    std::cout << std::endl;
    tmp = test;
    tmp.mirrorV();
    std::cout << tmp;
    std::cout << std::endl;
    tmp = test;
    tmp.mirrorSD();
    std::cout << tmp;
}



// int main() {
//     // Создание объекта SpreadSheet
//     SpreadSheet sheet(3, 3);

//     // Вывод исходной таблицы
//     std::cout << "Original SpreadSheet:" << std::endl;
//     std::cout << sheet << std::endl;

//     // Применение некоторых операций к таблице
//     sheet.mirrorH();
//     sheet.mirrorV();
//     sheet.mirrorD();
//     sheet.rotate(1);

//     // Вывод измененной таблицы
//     std::cout << "Transformed SpreadSheet:" << std::endl;
//     std::cout << sheet << std::endl;

//     // Удаление строки и столбца
//     sheet.removeRow(1);
//     sheet.removeCol(0);

//     // Вывод обновленной таблицы
//     std::cout << "Updated SpreadSheet:" << std::endl;
//     std::cout << sheet << std::endl;

//     return 0;
// }


// int main() {
//     // Создание объекта SpreadSheet
//     SpreadSheet sheet(3, 3);

//     // Заполнение ячеек таблицы некоторыми значениями
//     // for (size_t i = 0; i < sheet.row(); ++i) {
//     //     for (size_t j = 0; j < sheet.col(); ++j) {
//     //         sheet[i][j] = static_cast<Cell>(i * sheet.col() + j);
//     //     }
//     // }

//     // Вывод исходной таблицы
//     std::cout << "Original SpreadSheet:" << std::endl;
//     std::cout << sheet << std::endl;

//     // Применение некоторых операций к таблице
//     sheet.mirrorH();
//     sheet.mirrorV();
//     sheet.mirrorD();
//     sheet.rotate(1);

//     // Вывод измененной таблицы
//     std::cout << "Transformed SpreadSheet:" << std::endl;
//     std::cout << sheet << std::endl;

//     // Удаление строк и столбцов
//     sheet.removeRow(1);
//     sheet.removeCol(0);

//     // Вывод обновленной таблицы
//     std::cout << "Updated SpreadSheet:" << std::endl;
//     std::cout << sheet << std::endl;

//     return 0;
// }

// int main() {
// SpreadSheet ob(2, 2);
// std::vector<int> v{33, 44, 55};
// std::string i = "hy";
// ob[0][0] = v.front();
// ob[0][1] = v[1];
// ob[1][0] = v[2];
// ob[1][1] = i;
// double d = ob[0][1];
// // Cell ob1(65);
// std::cout << ob[0][0] << std::endl;
// std::cout << ob[0][1] << std::endl;
// std::cout << ob[1][0] << std::endl;
// std::cout << ob[1][1] << std::endl;
//     return 0;
// }