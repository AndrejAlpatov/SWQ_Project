//============================================================================
// Copyright   : This file is in the public domain
// Description : test generated version information
//============================================================================

#include "AutoTest.h"

class TestQttestBehaviour: public QObject
{
    Q_OBJECT

  private slots:
        void firstTestCase() {
            QCOMPARE(someAttributeWhichIsUsedInTestCases, 0);
            someAttributeWhichIsUsedInTestCases=1;
            QCOMPARE(someAttributeWhichIsUsedInTestCases, 1);
            QCOMPARE(objectNumber, 1);
        }

        void secondTestCase() {
            if (someAttributeWhichIsUsedInTestCases != 0) {
		QWARN("someAttributeWhichIsUsedInTestCases was changed by another test case!");
	    }
            someAttributeWhichIsUsedInTestCases = 2;
            QCOMPARE(someAttributeWhichIsUsedInTestCases, 2);
            QCOMPARE(objectNumber, 1);
        }

        void initTestCase() {
            qDebug() << "initTestCase by object" << objectNumber;
        }

        void cleanupTestCase() {
            qDebug() << "cleanupTestCase by object" << objectNumber;
        }

    public:
        TestQttestBehaviour()
            : someAttributeWhichIsUsedInTestCases(0)
        {
            ++objectCount;
            objectNumber = objectCount;
            qDebug() << "Constructor of object" << objectNumber;
        }

        ~TestQttestBehaviour()
        {
            --objectCount;
            qDebug() << "Destructor of object" << objectNumber;
        }

    private:
        static int objectCount;
        int objectNumber;
        int someAttributeWhichIsUsedInTestCases;
};

int TestQttestBehaviour::objectCount = 0;

AUTO_TEST_SUITE(TestQttestBehaviour);

#include "testQttestBehaviour.moc"
