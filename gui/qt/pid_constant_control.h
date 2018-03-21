#pragma once

#include <QObject>
#include <QValidator>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QSpinBox>
#include <QApplication>
#include <QGridLayout>

class pid_constant_control : public QGroupBox
{
  Q_OBJECT

public:
  pid_constant_control(QWidget * parent = Q_NULLPTR);

  void set_values(int multiplier, int exponent);

private:
  void set_constant();

  QSpinBox * multiplier_spinbox;
  QSpinBox * exponent_spinbox;
  QLineEdit * constant_lineedit;

signals:
  void values_changed(int multiplier, int exponent);

private slots:
  void multiplier_spinbox_valueChanged(int value);
  void exponent_spinbox_valueChanged(int value);
  void constant_lineedit_textEdited(const QString&);
  void constant_lineedit_editingFinished();
};

// This subclass of QDoubleValidator was designed to disallow user input of invalid
// digits and characters. QDoubleValidator allows the user to input values which
// are outside of a desired range by assigning a QValidator state of "Intermediate"
// during input and validating the digit string as a whole, upon completion.
// In this subclass, each digit entered is validated, when entered, immediately,
// based on assigned parameters. If the digit entered would make the value greater/less
// than the assigned range, the input is declared "Invalid" and is not accepted.
class pid_constant_validator : public QDoubleValidator
{
public:
  pid_constant_validator(double bottom, double top, int decimals,
    QObject * parent)
    : QDoubleValidator(bottom, top, decimals, parent)
  {}

  QValidator::State validate(QString & s, int & i) const
  {
    if (s.isEmpty())
    {
      return QValidator::Intermediate;
    }

    QChar decimalPoint = locale().decimalPoint();

    // Prevents user from entering too many digits
    // after the decimal point
    if(s.indexOf(decimalPoint) != -1)
    {
      int charsAfterPoint = s.length() - s.indexOf(decimalPoint) - 1;

      if (charsAfterPoint > decimals())
      {
        return QValidator::Invalid;
      }
    }

    bool ok;
    double d = locale().toDouble(s, &ok);
    // Disallows entering a value which is outside of the
    // declared range.
    if (ok && d >= bottom() && d <= top())
    {
      return QValidator::Acceptable;
    }
    else
    {
      return QValidator::Invalid;
    }
  }
};
