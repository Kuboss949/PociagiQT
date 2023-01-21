//
// Created by creaz on 21.01.2023.
//

#ifndef UNTITLED5_QTCHNGPROP_H
#define UNTITLED5_QTCHNGPROP_H

#include <QString>
#include <QPalette>

template <typename T>
void changeBackground(T *obj, QString resourcePath){
    QPalette palette = obj->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(resourcePath)));
    obj->setPalette(palette);
}

#endif //UNTITLED5_QTCHNGPROP_H
