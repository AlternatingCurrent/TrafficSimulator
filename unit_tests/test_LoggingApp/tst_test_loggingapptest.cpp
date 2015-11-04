#include <QString>
#include <QtTest>
#include <sys/stat.h>
#include "../../contextobject.cpp"
#include "../../concreteinterceptor.cpp"
#include "../../loggingapp.cpp"

class Test_LoggingAppTest : public QObject
{
    Q_OBJECT

public:
    Test_LoggingAppTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1_data();
    void testCase1();
    bool fileExists(const std::string& filename);
    void testCase2();
};

Test_LoggingAppTest::Test_LoggingAppTest()
{
}

void Test_LoggingAppTest::initTestCase()
{

    // test loggingapp ::createInterceptor()
    LoggingApp * logger = NULL;
    logger = new LoggingApp();
    logger->createInterceptor();
    QVERIFY(logger != NULL);

}

void Test_LoggingAppTest::cleanupTestCase()
{
}

void Test_LoggingAppTest::testCase1_data()
{

}

void Test_LoggingAppTest::testCase1()
{
    // set up the environment to test
    int speed = 5;
    ContextObject cObj = ContextObject(speed);

    LoggingApp * logger = NULL;
    logger = new LoggingApp();
    logger->createInterceptor();

    logger->cInterceptor.event_callback(&cObj);
    // test to see that speed has been added to the logs
    QVERIFY(logger->speed_time_values[0].speed == speed);
}


bool Test_LoggingAppTest::fileExists(const std::string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }
    return false;
}

void Test_LoggingAppTest::testCase2()
{
    // set up the environment to test
    int speed = 5;
    ContextObject cObj = ContextObject(speed);

    LoggingApp * logger = NULL;
    logger = new LoggingApp();
    logger->createInterceptor();
    logger->cInterceptor.event_callback(&cObj);
    // test to make sure file is written with correct data
    logger->updateTextFile();
    const std::string filename = "logs.txt";
    // test to see that logs.txt has been created
    QVERIFY(fileExists(filename));
}

QTEST_APPLESS_MAIN(Test_LoggingAppTest)

#include "tst_test_loggingapptest.moc"
