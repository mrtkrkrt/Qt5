#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QString>

bool createDir(QString path){
    QDir dir(path);

    if(dir.exists()){
        qInfo() << "ALready exists!";
        return true;
    }

    if(dir.mkpath(path)){
        qInfo() << "Created!";
        return true;
    }else{
        qInfo() << "Could not create!";
        return false;
    }
}

bool renameDir(QString path, QString name){
    QDir dir(path);

    if(!dir.exists()){
        qInfo() << "Path does not exist!";
        return false;
    }

    int pos = path.lastIndexOf(QDir::separator());
    QString parent = path.mid(0, pos);
    QString newPath = parent + QDir::separator() + name;

    qInfo() << "Absolute: " << dir.absolutePath();
    qInfo() << "Parent: " << parent;
    qInfo() << "New: " << newPath;

    return  dir.rename(path,newPath);
}

bool remove(QString path) {
    qInfo() << "Removing: " << path;
    QDir dir(path);

    if(!dir.exists()) {
        qInfo() << "Path does not exist!";
        return false;
    }

    //DANGER!!!
    return dir.removeRecursively();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
