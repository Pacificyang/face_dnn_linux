#include "ExtractFeature_.h"
#include "FaceDetect.h"
#include "ComputeDistance.h"
#include "Register.h"
#include "Recognition.h"
#include <time.h>
#include "qtsinglecoreapplication.h"

void report(const QString& msg)
{
    qDebug("[%i] %s", (int)QCoreApplication::applicationPid(), qPrintable(msg));
}

class MainClass : public QObject
{
    Q_OBJECT
public:
    MainClass()
        : QObject()
    {
        Caffe_Predefine();
        //Dlib_Predefine();
        m_model.LoadVector("model");
    }

public slots:
    void handleMessage(const QString& message)
    {
        report( "Message received: \"" + message + "\"");
        //识别
        //cout << "message:" << message << endl;
        cv::Mat test = cv::imread(message.toStdString());
        string result = m_model.Predict(test);
        cout << "it's model:"<< result << endl;

    }
private:
    Recognition m_model;
};

int main(int argc, char* argv[])
{

    QtSingleCoreApplication app(argc, argv);

    if (app.isRunning()) {
        //QString msg(QString("Hi master, I am %1.").arg(QCoreApplication::applicationPid()));
        if(argc<2){
            cout << "please input ./face_dnn.sh + image location " << endl;
            return 0;
        }
        //QString msg(QString(argv[1]));
        QString msg(argv[1]);
        bool sentok = app.sendMessage(msg, 2000);
        QString rep("Another instance is running, so I will exit.");
        rep += sentok ? " Message sent ok." : " Message sending failed; the other instance may be frozen.";
        report(rep);
        return 0;
    } else {
        report("No other instance is running; so I will.");
        MainClass mainObj;
        QObject::connect(&app, SIGNAL(messageReceived(const QString&)),
                         &mainObj, SLOT(handleMessage(const QString&)));

        return app.exec();
    }





    /*
    //新人添加头像信息
    string label;
    string path = "user/";
    string file_name = "mike";
    string suffix = ".jpg";
    string img_file = path + file_name + suffix;
    cv::Mat test = cv::imread(img_file);

    user.JoinFaceSpace(test, "user", file_name);
    */

    /*
//初始训练
    Recognition Val;
    vector<cv::Mat> imgArray;
    vector<string> labelArray;
    for (int i = 0; i < 19; i++)//读入图片
    {
        string path = "model/";                    ////从前端的图片先获取特性，再保存到user
        string file_name = to_string(i);
        string suffix = ".jpg";
        string img_file = path + file_name+ suffix;
        cv::Mat img = cv::imread(img_file);
        imgArray.push_back(img);
        labelArray.push_back(file_name);
    }

    for (int j = 0; j < 19; j++) {
        Val.JoinFaceSpace(imgArray[j], "model", labelArray[j]);
    }
    */

    //imshow("Face Recognition", test);
    //cv::waitKey(0);

    //return 0;

} 

#include "main.moc"
