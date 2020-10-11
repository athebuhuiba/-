#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class player : public QObject
{
    Q_OBJECT
public:
    explicit player(QObject *parent = nullptr);
    int num;
    bool camp;//阵营：非零为红；0为黑
    bool state;//玩家0死 非0生
    bool pos;//0村长
    bool eye;//0睁眼
    int vote;//投票序号
    double voted;//被投票数




signals:


public slots:
};

#endif // PLAYER_H
