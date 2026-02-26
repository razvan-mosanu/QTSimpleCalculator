#ifndef ARITMETICA_H
#define ARITMETICA_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QString>

class AranjareButoane : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *editA;
    QLineEdit *editB;
    QLabel *labelRezultat;
    struct DateInput{ double a; double b; bool valid;};
    DateInput iaDatele();

public:
    explicit AranjareButoane(QWidget *parent = nullptr);
public slots:
    void sum();
    void prod();
    void div();
    void dif();
    void putere();
    void radical();
    void afiseazaMesaj(const QString& mesaj);
};

#endif // ARITMETICA_H
