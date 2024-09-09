#include "databin.h"

databin::databin(QObject *parent)
    : QObject{parent}
{
    QVector<QVector<int>> arr1 = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {1, 0, 0, 1}
    };

    QVector<QVector<int>> arr2 = {
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 0, 1, 1}
    };

    QVector<QVector<int>> arr3 = {
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1}
    };

    QVector<QVector<int>> arr4 = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    QVector<QVector<int>> arr5 = {
        {1, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 1}
    };

    QVector<QVector<int>> arr6 = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0}
    };

    QVector<QVector<int>> arr7 = {
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1}
    };

    QVector<QVector<int>> arr8 = {
        {1, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 0}
    };

    QVector<QVector<int>> arr9 = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    QVector<QVector<int>> arr10 = {
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0}
    };

    QVector<QVector<int>> arr11 = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 1, 0},
        {1, 0, 0, 1}
    };

    QVector<QVector<int>> arr12 = {
        {1, 1, 0, 0},
        {0, 1, 1, 1},
        {0, 1, 1, 0},
        {0, 0, 0, 1}
    };

    QVector<QVector<int>> arr13 = {
        {0, 0, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 1, 0, 1}
    };

    QVector<QVector<int>> arr14 = {
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    QVector<QVector<int>> arr15 = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    QVector<QVector<int>> arr16 = {
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1}
    };

    QVector<QVector<int>> arr17 = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    QVector<QVector<int>> arr18 = {
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0}
    };

    QVector<QVector<int>> arr19 = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0}
    };

    QVector<QVector<int>> arr20 = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {1, 0, 0, 1}
    };

    dataarr[1] = arr1;
    dataarr[2] = arr2;
    dataarr[3] = arr3;
    dataarr[4] = arr4;
    dataarr[5] = arr5;
    dataarr[6] = arr6;
    dataarr[7] = arr7;
    dataarr[8] = arr8;
    dataarr[9] = arr9;
    dataarr[10] = arr10;
    dataarr[11] = arr11;
    dataarr[12] = arr12;
    dataarr[13] = arr13;
    dataarr[14] = arr14;
    dataarr[15] = arr15;
    dataarr[16] = arr16;
    dataarr[17] = arr17;
    dataarr[18] = arr18;
    dataarr[19] = arr19;
    dataarr[20] = arr20;


}
