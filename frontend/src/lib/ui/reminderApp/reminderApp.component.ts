import { Component, ElementRef, OnInit, ViewChild } from "@angular/core";
import { List } from "src/lib/data-access/list";
import { Reminder } from "src/lib/data-access/reminder";
import { ReminderApp } from "src/lib/data-access/reminderApp";
import { AppService } from "src/lib/feature/appService.service";


@Component({
  selector: 'reminderApp',
  templateUrl: './reminderApp.component.html',
  styleUrls: ['./reminderApp.component.scss'],
})

export class ReminderAppComponent implements OnInit{

  constructor(private appService: AppService){}
  app?: ReminderApp;
  showToday: boolean = false;
  showFlagged: boolean = false;
  flaggedList: List;
  todayList: List;
  listPos?: number;
  focus: boolean = false;
  @ViewChild("i") listTitleInput: ElementRef;

  ngOnInit(): void {
    this.appService.getApp().subscribe((result: ReminderApp) => this.app = result);
  }

  addEmptyList(){
    this.hideList();
    let newList: List = {title: "", reminders: [], visible: true};
    this.listPos = this.app.lists.push(newList) - 1;
    newList.position = (this.listPos == 0) ? 1 : this.app.lists[this.listPos -1].position + 1;
    this.appService.postList(newList).subscribe((response:List) => this.app.lists[this.app.lists.length - 1].id = response.id);
  }

  deleteList(id: number){
    this.app.lists = this.app.lists.filter((list) => list.id != id);
    this.appService.deleteList(id).subscribe();
  }

  showList(showList: List){
    this.app.lists.forEach((list) => list.visible = (showList == list));
  }
  hideList(){
    this.showToday = false;
    this.showFlagged = false;
    this.app.lists.forEach((list) => list.visible = false);
  }
  changeListTitle(list: List){
    this.appService.putList(list).subscribe();
  }
  showTodaysReminders(){
    this.hideList();
    this.todayList = {title:"Today", reminders:[]}
    let today: string = this.appService.getToday();
    this.app.lists.forEach((list)=> list.reminders.forEach((rem) => {if (rem.timestamp == today) {rem.listId = list.id; this.todayList.reminders.push(rem)}}));
    this.showToday = true;
  }
  deleteSpecialReminder(rem: Reminder){
    let listIndex = this.app.lists.findIndex((list) => list.id == rem.listId);
    this.app.lists[listIndex].reminders = this.app.lists[listIndex].reminders.filter((reminder) => reminder.id != rem.id)
  }
  changeSpecialReminder(rem:Reminder){
    let listIndex = this.app.lists.findIndex((list) => list.id == rem.listId);
    let remIndex = this.app.lists[listIndex].reminders.findIndex((reminder) => reminder.id == rem.id);
    this.app.lists[listIndex].reminders[remIndex] = rem;
  }
  showFlaggedReminders(){
    this.hideList();
    this.flaggedList = {title:"Flagged", reminders:[]}
    this.app.lists.forEach((list)=> list.reminders.forEach((rem) => {if (rem.flag == 1) {rem.listId = list.id; this.flaggedList.reminders.push(rem)}}));
    this.showFlagged = true;
  }
  focusInput() {
    if(this.focus){
      this.listTitleInput.nativeElement.focus();
    }
    this.focus = false;
  }
}
