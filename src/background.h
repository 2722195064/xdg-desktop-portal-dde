#pragma once

#include <QDBusAbstractAdaptor>
#include <QDBusObjectPath>

class BackgroundPortal : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.freedesktop.impl.portal.Background")
public:
    explicit BackgroundPortal(QObject *parent);
    ~BackgroundPortal() = default;
};
