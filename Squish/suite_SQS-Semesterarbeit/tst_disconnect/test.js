import * as names from 'names.js';

function main() {
    startApplication("SQS-Semesterarbeit");
    clickButton(waitForObject(names.groupBoxMachineControlPushButtonConnectQPushButton));
    mouseClick(waitForObject(names.groupBoxInputTextEditInputQTextEdit), 169, 67, Qt.NoModifier, Qt.LeftButton);
    type(waitForObject(names.groupBoxInputTextEditInputQTextEdit), "disconnect");
    clickButton(waitForObject(names.groupBoxMachineControlPushButtonStartQPushButton));
    test.compare(waitForObjectExists(names.groupBoxMachineStatusLabelConnectionStatusQLabel).styleSheet, "border-radius: 6px; background-color: rgb(203, 47, 47)");
}
