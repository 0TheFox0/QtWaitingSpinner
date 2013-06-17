#include "qtwaitingspinner.h"
#include "qtwaitingspinnerplugin.h"

#include <QtPlugin>

QtWaitingSpinnerPlugin::QtWaitingSpinnerPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QtWaitingSpinnerPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;
    
    // Add extension registrations, etc. here
    
    m_initialized = true;
}

bool QtWaitingSpinnerPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QtWaitingSpinnerPlugin::createWidget(QWidget *parent)
{
    return new QtWaitingSpinner(parent,12,7,5,10);
}

QString QtWaitingSpinnerPlugin::name() const
{
    return QLatin1String("QtWaitingSpinner");
}

QString QtWaitingSpinnerPlugin::group() const
{
    return QLatin1String("");
}

QIcon QtWaitingSpinnerPlugin::icon() const
{
    return QIcon();
}

QString QtWaitingSpinnerPlugin::toolTip() const
{
    return QLatin1String("");
}

QString QtWaitingSpinnerPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool QtWaitingSpinnerPlugin::isContainer() const
{
    return false;
}

QString QtWaitingSpinnerPlugin::domXml() const
{
    return QLatin1String("<widget class=\"QtWaitingSpinner\" name=\"qtWaitingSpinner\">\n</widget>\n");
}

QString QtWaitingSpinnerPlugin::includeFile() const
{
    return QLatin1String("qtwaitingspinner.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(qtwaitingspinnerplugin, QtWaitingSpinnerPlugin)
#endif // QT_VERSION < 0x050000
