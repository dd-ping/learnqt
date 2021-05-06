#include <QGuiApplication>
//#include <QQmlApplicationEngine>
#include<QtQuick/QQuickView>
#include<QtQml>
#include"testobj.h"
int main(int argc, char *argv[])
{
 //   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //注册qml可用类型 qmlRegisterSingletonType() 注册单例类型 qmlRegisterType()非单例

    /* template<typename T>
  int qmlRegisterType(const char *uri, int versionMajor, int versionMinor, const char *qmlName);
  uri 包名 1 ， 0 分别是版本versionMajor|versionMinor ，qmlname 是qml中要使用的类名。
*/
    qmlRegisterType<TestObj>("he.TestObj.Color",1,0,"TestObj");

    QQuickView viewer;
    viewer.rootContext()->setContextProperty("rootv",&viewer);
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.setSource(QUrl("qrc:///main.qml"));
    viewer.show();

//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

    return app.exec();
}
