#ifndef TESTOBJ_H
#define TESTOBJ_H

#include <QObject>
#include<QColor>
#include<QTime>
#include<QDateTime>
#include<QTimerEvent>
class TestObj : public QObject
{
    Q_OBJECT
    //qml要使用 c++ 枚举需要使用QENUMS来注册
    Q_ENUMS(GenerateAlgorithm)

    //Q_PROPERTY宏 可以 通过元对象系统访问属性，通过它定义的属性可以在qml中访问、修改；
    //也可以在属性变化的时候发射特定信号。 使用该宏必须是 QOBJECT 后裔，和使用 Q_OBJECT 宏
    /*
     * Q_PROPERTY(type name *属性 名
             (READ getFunction [WRITE setFunction *可选，声明一个设定属性的函数，他指定的属性，\
函数没有返回值，只能有一个与属性函数类型匹配的参数] |
              MEMBER memberName [(READ getFunction | WRITE setFunction)])* READ 标记，\
MEMBER 标记 ， 必须二选一 ：声明一个读取属性的函数，该函数一般没有参数，返回它定义的属性

             [RESET resetFunction]
             [NOTIFY notifySignal] *可选配置，给属性关联一个信号(该信号必须在类中声明)，当属性值发生变化就会
触发信号，信号的参数，一般就是定义的属性。
             [REVISION int]
             [DESIGNABLE bool]
             [SCRIPTABLE bool]
             [STORED bool]
             [USER bool]
             [CONSTANT]
             [FINAL])
*/
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChange)
    Q_PROPERTY(QColor timeColor READ timeColor)

public:
    explicit TestObj(QObject *parent = nullptr);

    ~TestObj();

    enum GenerateAlgorithm{
        RandomRGB,
        RandomRed,
        RandomGreen,
        RandomBlue,
        LinearIncrease
    };
//使用Q_INVOKABLE宏定义类成员函数，该方法就能被元对象系统使用
    Q_INVOKABLE GenerateAlgorithm algorithm()const;
    Q_INVOKABLE void setAlgorithm(GenerateAlgorithm algorithm);

    QColor color()const;
    void setColor(const QColor & color );
    QColor timeColor()const;

protected:
    void timerEvent(QTimerEvent * e);
private:
    GenerateAlgorithm m_algorithm;
    QColor m_currentColor;
    int m_nColorTimer;

signals:
    void colorChange(const QColor & color);
    void currenTime(const QString & strTime);
public slots:
    void start();
    void stop();
};

#endif // TESTOBJ_H
