#ifndef QTWAITINGSPINNER_H
#define QTWAITINGSPINNER_H

#include <QtCore/QTimer>

#include <QWidget>
#include <QColor>

#if defined(SHAREDLIB_LIBRARY)
#  define SHAREDLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SHAREDLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

class SHAREDLIBSHARED_EXPORT QtWaitingSpinner : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(int linesNumber READ linesNumber WRITE setlinesNumber NOTIFY linesNumberChanged)
    Q_PROPERTY(int Length READ Length WRITE setLength NOTIFY LengthChanged)
    Q_PROPERTY(int Width READ Width WRITE setWidth NOTIFY WidthChanged)
    Q_PROPERTY(int Radius READ Radius WRITE setRadius NOTIFY RadiusChanged)
    Q_PROPERTY(qreal Roundness READ Roundness WRITE setRoundness NOTIFY RoundnessChanged)
    Q_PROPERTY(QColor Color READ Color WRITE setColor NOTIFY ColorChanged)
    Q_PROPERTY(qreal Speed READ Speed WRITE setSpeed NOTIFY SpeedChanged)
    Q_PROPERTY(int Trail READ Trail WRITE setTrail NOTIFY TrailChanged)
    Q_PROPERTY(int Opacity READ Opacity WRITE setOpacity NOTIFY OpacityChanged)
public:
    explicit QtWaitingSpinner( QWidget *parent = 0,int linesNumber = 12, int length = 7, int width = 5, int radius = 10);

public Q_SLOTS:
    void start();
    void finish();

public:
    void setlinesNumber(int linesNumber);
    void setLength(int length);
    void setWidth(int width);
    void setRadius(int radius);
    void setRoundness(qreal roundness);
    void setColor(QColor color);
    void setSpeed(qreal speed);
    void setTrail(int trail);
    void setOpacity(int minOpacity);

    int linesNumber() const;

    int Radius() const;

    qreal Roundness() const;

    QColor Color() const;

    qreal Speed() const;

    int Trail() const;

    int Opacity() const;

    int Length() const;

    int Width() const;

signals:
    void linesNumberChanged(int arg);

    void RadiusChanged(int arg);

    void RoundnessChanged(qreal arg);

    void ColorChanged(QColor arg);

    void SpeedChanged(qreal arg);

    void TrailChanged(int arg);

    void OpacityChanged(int arg);

    void LengthChanged(int arg);

    void WidthChanged(int arg);

private Q_SLOTS:
    void rotate();
    void updateSize();
    void updateTimer();

protected:
    void paintEvent(QPaintEvent *ev);

private:
    static int countTimeout(int lines, qreal speed);
    static int lineDistance(int from, int to, int lines);
    static QColor countTrailColor(int distance, int lines, int trail, int minOpacity, QColor color);

private:
    int myLinesNumber;
    int myLength;
    int myWidth;
    int myRadius;
    qreal myRoundness; //0..100
    QColor myColor;
    qreal mySpeed; // in rounds per second
    int myTrail;
    int myOpacity;

private:
    QTimer *myTimer;
    int myCurrentCounter;
};

#endif
