#ifndef UNTITLED5_QTCHNGPROP_H
#define UNTITLED5_QTCHNGPROP_H

#include <QString>
#include <QPalette>
/**
 * @brief Function that change background of given object
 * @tparam T type of QT object
 * @param obj pointer to object
 * @param resourcePath path to background
 */
template <typename T>
void changeBackground(T *obj, QString resourcePath){
    QPalette palette = obj->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(resourcePath)));
    obj->setPalette(palette);
}

#endif //UNTITLED5_QTCHNGPROP_H
