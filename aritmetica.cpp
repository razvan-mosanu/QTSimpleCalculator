#include "aritmetica.h"
#include "mathtools.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <cmath>

AranjareButoane::AranjareButoane(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *principal = new QVBoxLayout(this);
    QFormLayout *date = new QFormLayout();
    editA = new QLineEdit(this);
    editB = new QLineEdit(this);
    labelRezultat = new QLabel("Rezultat: 0", this);
    date->addRow("Valoare a:", editA);
    date->addRow("Valoare b:", editB);
    date->addRow(labelRezultat);
    principal->addLayout(date);
    principal->addStretch();

    QPushButton *butonPlus = new QPushButton("Aduna", this);
    QPushButton *butonMinus = new QPushButton("Scade", this);
    QPushButton *butonDiv = new QPushButton("Imparte", this);
    QPushButton *butonProd = new QPushButton("Inmulteste", this);
    QPushButton *butonPutere = new QPushButton("Ridica la putere", this);
    QPushButton *butonRadical = new QPushButton("Radacina din a de ordinul b", this);

    principal->addWidget(butonPlus);
    principal->addWidget(butonMinus);
    principal->addWidget(butonDiv);
    principal->addWidget(butonProd);
    principal->addWidget(butonPutere);
    principal->addWidget(butonRadical);

    connect(butonPlus, &QPushButton::clicked, this, &AranjareButoane::sum);
    connect(butonMinus, &QPushButton::clicked, this, &AranjareButoane::dif);
    connect(butonProd, &QPushButton::clicked, this, &AranjareButoane::prod);
    connect(butonDiv, &QPushButton::clicked, this, &AranjareButoane::div);
    connect(butonPutere, &QPushButton::clicked, this, &AranjareButoane::putere);
    connect(butonRadical, &QPushButton::clicked, this, &AranjareButoane::radical);
}

AranjareButoane::DateInput AranjareButoane::iaDatele()
{
    bool okA, okB;
    double a = editA->text().toDouble(&okA);
    double b = editB->text().toDouble(&okB);
    return {a, b, okA && okB};
}

void AranjareButoane::sum()
{
    DateInput d = iaDatele();
    if(d.valid) labelRezultat->setText("Rezultat: " + QString::number(d.a + d.b));
    else afiseazaMesaj("Introdu date corecte!");
}

void AranjareButoane::div()
{
    DateInput d = iaDatele();
    if(d.valid == false)
    {
        afiseazaMesaj("Introdu date corecte!");
        return;
    }
    if (d.b == 0)
    {
        afiseazaMesaj("Eroare: Divizia la 0!");
        return;
    }
    labelRezultat->setText("Rezultat: " + QString::number(d.a / d.b));
}

void AranjareButoane::prod()
{
    DateInput d = iaDatele();
    if(d.valid == false)
    {
        afiseazaMesaj("Introdu date corecte!");
        return;
    }
    labelRezultat->setText("Rezultat: " + QString::number(d.a * d.b));
}

void AranjareButoane::afiseazaMesaj(const QString& mesaj)
{
    labelRezultat->setText(mesaj);
}

void AranjareButoane::dif()
{
    DateInput d = iaDatele();
    if(d.valid == false)
    {
        afiseazaMesaj("Introdu date corecte!");
        return;
    }
    labelRezultat->setText("Rezultat: " + QString::number(d.a - d.b));
}

void AranjareButoane::putere()
{
    DateInput d = iaDatele();
    if(d.valid == false)
    {
        afiseazaMesaj("Introdu date corecte!");
        return;
    }
    d.b = (int)d.b;
    if(d.b < 0)
    {
        labelRezultat->setText("Rezultat: " + QString::number(1.0 / MathTools::Ridicare_la_Putere(d.a, -d.b)));
        return;
    }
    labelRezultat->setText("Rezultat: " + QString::number(MathTools::Ridicare_la_Putere(d.a, d.b)));
}

void AranjareButoane::radical()
{
    DateInput d = iaDatele();
    if(d.valid == false)
    {
        afiseazaMesaj("Introdu date corecte!");
        return;
    }
    d.b = (int)d.b;
    if (d.a < 0 && (int)d.b % 2 == 0)
    {
        afiseazaMesaj("Rezultat: 0");
        return;
    }
    if (d.b == 0)
    {
        afiseazaMesaj("Rezultat: 1");
        return;
    }
    double x = d.a / d.b;
    double epsilon = 0.000001;
    double diferenta;
    do
    {
        double xNext = (1.0 / d.b) * ((d.b - 1) * x + d.a / MathTools::Ridicare_la_Putere(x, d.b - 1));
        diferenta = std::abs(xNext - x);
        x = xNext;
    } while (diferenta > epsilon);
    labelRezultat->setText("Rezultat: " + QString::number(x));
}
