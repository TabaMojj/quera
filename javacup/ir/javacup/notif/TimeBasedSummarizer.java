package ir.javacup.notif;

import com.xos.Notification;
import com.xos.NotificationSummarizer;
import com.xos.Priority;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class TimeBasedSummarizer implements NotificationSummarizer {

    @Override
    public List<Notification> summarize(List<Notification> notifications) {
        ArrayList<Notification> list = new ArrayList<>();

        notifications.sort((o1, o2) -> {
            int oi1 = change(o1.getPriority());
            int oi2 = change(o2.getPriority());
            if (oi1 > oi2) {
                return -1;
            } else if (oi1 < oi2) {
                return 1;
            } else {
                return o2.getTime().compareTo(o1.getTime());
            }
        });

        Date now = new Date();
        for (Notification notification : notifications) {
            if (now.getTime() - notification.getTime().getTime() < 5 * 60 * 1000) {
                list.add(notification);
            }
        }

        return list;
    }

    private int change(Priority p) {
        switch (p) {
            case LOW:
                return 0;
            case DEFAULT:
                return 1;
            case HIGH:
                return 2;
            default:
                return -1;
        }
    }
}
