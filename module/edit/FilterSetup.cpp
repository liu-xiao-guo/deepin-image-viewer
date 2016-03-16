#include "FilterSetup.h"
#include "FiltersPreview.h"
#include <QTabWidget>
#include <QBoxLayout>
#include <dbasebutton.h>
#include <dimagebutton.h>

using namespace Dtk::Widget;

FilterSetup::FilterSetup(QWidget *parent)
    : QWidget(parent)
{
    QTabWidget *mTab = new QTabWidget();
    m_preview = new FiltersPreview();
    mTab->addTab(m_preview, tr("Simple"));

    DBaseButton *cancel = new DBaseButton();
    cancel->setText(tr("Cancel"));
    DBaseButton *save = new DBaseButton();
    save->setText(tr("Save"));

    QHBoxLayout *hb = new QHBoxLayout();
    hb->addSpacing(0);
    hb->addWidget(cancel);
    hb->addWidget(save);

    QVBoxLayout *vb = new QVBoxLayout();
    setLayout(vb);
    vb->addWidget(mTab);
    vb->addLayout(hb);
}

void FilterSetup::setImage(const QString &path)
{
    m_preview->setImage(QImage(path));
}
