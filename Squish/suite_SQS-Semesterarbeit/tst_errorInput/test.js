import * as names from 'names.js';

function main() {
    startApplication("SQS-Semesterarbeit");
    clickButton(waitForObject(names.groupBoxMachineControlPushButtonConnectQPushButton));
    mouseClick(waitForObject(names.groupBoxInputTextEditInputQTextEdit), 234, 156, Qt.NoModifier, Qt.LeftButton);
    type(waitForObject(names.groupBoxInputTextEditInputQTextEdit), "error");
    clickButton(waitForObject(names.groupBoxMachineControlPushButtonStartQPushButton));
    test.compare(waitForObjectExists(names.groupBoxMachineStatusLabelErrorStatusQLabel).styleSheet, "border-radius: 6px; background-color: rgb(203, 47, 47)");
    clickButton(waitForObject(names.groupBoxMachineControlPushButtonResetErrorAndEStopQPushButton));
    test.compare(waitForObjectExists(names.groupBoxMachineStatusLabelErrorStatusQLabel).styleSheet, "border-radius: 6px; background-color: rgb(27, 193, 00)");
}
