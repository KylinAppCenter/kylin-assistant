/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp com.kylin.assistant.qsessiondbus.xml -a sessionadaptor -c SessionAdaptor
 *
 * qdbusxml2cpp is Copyright (C) 2015 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef SESSIONADAPTOR_H
#define SESSIONADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

/*
 * Adaptor class for interface com.kylin.assistant.qsessiondbus
 */
class SessionAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.kylin.assistant.qsessiondbus")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"com.kylin.assistant.qsessiondbus\">\n"
"    <method name=\"demoInfo\">\n"
"      <arg direction=\"out\" type=\"s\"/>\n"
"    </method>\n"
"    <method name=\"exitService\"/>\n"
"  </interface>\n"
        "")
public:
    SessionAdaptor(QObject *parent);
    virtual ~SessionAdaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    QString demoInfo();
    void exitService();
Q_SIGNALS: // SIGNALS
};

#endif
