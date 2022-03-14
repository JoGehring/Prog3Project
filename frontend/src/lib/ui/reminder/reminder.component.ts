import { Component, ElementRef, EventEmitter, Input, Output, ViewChild } from "@angular/core";
import { Reminder } from "src/lib/data-access/reminder";
import { AppService } from "src/lib/feature/appService.service";


@Component({
  selector: 'reminder',
  templateUrl: './reminder.component.html',
  styleUrls: ['./reminder.component.scss']
})

export class ReminderComponent{

  constructor(private appService: AppService){}

  @Input() reminder: Reminder;
  @Input() selectedOnCreate: boolean;
  @Output()  deleteReminderEvent = new EventEmitter<Reminder>();
  @Output() changeReminderEvent = new EventEmitter<Reminder>();
  checked: boolean = false;
  @ViewChild('reminderTitleInput') reminderTitleInput: ElementRef;

  ngAfterViewInit(){
    if(this.selectedOnCreate){
      this.reminderTitleInput.nativeElement.focus();
    }
  }

  deleteReminder(){
    this.checked = !this.checked;
    setTimeout(() => {
      if(this.checked) this.deleteReminderEvent.emit(this.reminder);
    }, 3000);
  }

  changeReminder(){
    this.changeReminderEvent.emit(this.reminder);
  }
  changeFlag(){
    this.reminder.flag = (this.reminder.flag == 0) ? 1 : 0;
    this.changeReminder();
  }
}
