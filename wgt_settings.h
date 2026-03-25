#ifndef WGT_SETTINGS_H
#define WGT_SETTINGS_H

#include <QWidget>

namespace Ui {
class wgtSettings;
}

class Settings;

class wgtSettings : public QWidget {
    Q_OBJECT

public:
    explicit wgtSettings(Settings *s, QWidget *parent = nullptr);
    ~wgtSettings();

signals:
    void settingsChanged();

private slots:
    void on_hsldProblems_sliderMoved(int position);
    void on_spnProblems_valueChanged(int arg1);
    void on_btnApply_clicked();
    void on_btnCancel_clicked();

private:
    Ui::wgtSettings *ui;
    Settings *mSettings;
};

#endif // WGT_SETTINGS_H
