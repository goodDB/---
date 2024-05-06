#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// 动物定义
/// ，我暂时就想到用这个来输出动物定义
/// </summary>
class CAnimal
{
protected:
    string mName;

public:
    CAnimal(string name) : mName(name)
    {
        cout << "Animal constructor " << mName << endl;
    }
    virtual ~CAnimal()
    {
        cout << "Animal destructor " << mName << endl;
    }
};

/// <summary>
/// 这是马类定义
/// ，每个类有两个变量，这里这两个变量不知道具体是什么含义，参考鸟的定义，我编了两个变量
/// </summary>
class CHorse
{
protected:
    int mSpeed;
    int mLength;

public:
    CHorse(int speed, int length) : mSpeed(speed), mLength(length)
    {
        cout << "Horse constructor" << endl;
    }
    ~CHorse()
    {
        cout << "Horse destructor" << endl;
    }
};

/// <summary>
/// 这是鸟类定义
/// </summary>
class CBird
{
protected:
    int mWingspan;
    int mPower;

public:
    CBird(int wingspan, int power) : mWingspan(wingspan), mPower(power)
    {
        cout << "Bird constructor" << endl;
    }
    ~CBird()
    {
        cout << "Bird destructor" << endl;
    }
};

/// <summary>
/// 这是狮子类定义
/// </summary>
class CLion
{
protected:
    int mMane;
    int mAP;

public:
    CLion(int isMane, int ap = 500) : mMane(isMane), mAP(ap)
    {
        cout << "Lion constructor" << endl;
    }

    virtual void Talk()
    {
        if (mMane)
            Fight();
        else
            Hunt();
    }

    void Fight()
    {
        if (mMane)
            cout << "I’m in charge of protecting the territory!\nI won’t give in, cause I’m proud of all my scars!" << endl;
    }

    void Hunt()
    {
        if (!mMane)
            cout << "I do the hunting !\nI’ll get you ! You can’t run away!" << endl;
    }

    ~CLion()
    {
        cout << "Lion destructor" << endl;
    }
};

/// <summary>
/// 缝合类定义,复合类继承基础类，所以这里需要继承 CAnimal（动物类），也可以在每个动物基础类上继承 CAnimal（动物类）
/// ，但是我还是觉得复合类继承比较好，因为这个动物类只是有一个动物名称，在基础类中类名基本就能看出来每个类代表什么动物
/// ，这个东西每个人有每个人的看法，有自己的风格就好
/// 
/// 然后我研究了类的构造和解构的顺序是根据下面的继承定义顺序来的，构造是从左到右，解构是反过来
///  class CHippogriff : public CAnimal, public CLion, public CHorse, public CBird
/// </summary>
class CHippogriff : public CAnimal, public CLion, public CHorse, public CBird
{

public:
    CHippogriff(const char* name, int speed, int length, int wingspan, int power, bool isMane, int ap = 500) : CAnimal(name),
        CHorse(speed, length),
        CBird(wingspan, power),
        CLion(isMane, ap)
        
    {
        cout << "CHippogriff_constructor" << endl;
    }

    void Show()
    {
        cout << mName << " " << mSpeed << " " << mLength << endl;
        cout << "Wingspan:" << mWingspan << endl;
        cout << mName << " " << mSpeed << " " << mLength << endl;
        cout << "Power:" << mPower << endl;
        cout << mName << " " << mSpeed << " " << mLength << endl;
        cout << "This is a lion!" << endl;
        cout << "Attack Power = " << mAP << endl;
    }

    virtual void Talk() override
    {
        if (mMane)
            Fight();
        else
            Hunt();
    }

    ~CHippogriff()
    {
        cout << "CHippogriff destructor" << endl;
    }
};

/// <summary>
/// 主函数，也叫入口函数
/// </summary>
/// <returns></returns>
int main()
{
    CHippogriff Hippogriff((char*)"Hippogriff", 5, 8888, 2, 10000, 1);
    Hippogriff.Show();
    Hippogriff.Talk();

    cout << "" << endl;
    cout << "" << endl;

    CHippogriff Hippogriff2((char*)"Hippogriff", 5, 8888, 2, 10000, 1, 886);
    Hippogriff.Show();
    Hippogriff.Talk();
    return 0;
}