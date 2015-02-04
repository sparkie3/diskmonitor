#include "drivepanel.h"
#include "ui_drivepanel.h"

#include "udisks2wrapper.h"


/*
 *
 */
DrivePanel::DrivePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrivePanel)
{
  ui->setupUi(this);

  this -> model = new DrivePropertiesModel();
  ui -> tableView -> verticalHeader() -> hide();
  ui -> tableView -> horizontalHeader() -> setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
  ui -> tableView -> horizontalHeader() -> setStretchLastSection(true);
  ui -> tableView -> setModel(this -> model);

  connect(ui -> startSelfTestButton, SIGNAL(clicked()), this, SLOT(startSelfTest()));

}



/*
 *
 */
DrivePanel::~DrivePanel()
{
  delete model;
  delete ui;
}



/*
 *
 */
void DrivePanel::setDrive(Drive* drive)
{
  model -> updateDrive(drive);

  ui -> tableView -> setEnabled(drive -> isSmartSupported() && drive -> isSmartEnabled());
  ui -> startSelfTestButton -> setEnabled(drive -> isSmartSupported() && drive -> isSmartEnabled());
}



/*
 *
 */
void DrivePanel::refresh()
{
  model -> refreshAll();
}



/*
 *
 */
void DrivePanel::startSelfTest()
{
  Drive* currentDrive = model -> getDrive();

  if(currentDrive != NULL)
    UDisks2Wrapper::getInstance() -> startDriveSelfTest(currentDrive);
}
