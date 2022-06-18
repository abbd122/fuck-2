import os, sys, traceback

import cv2


class VideoPlan(object):
    def __init__(self, path):
        self.format_list = ['.mp4', '.rmvb']
        self.path = path
        self.total_secondes = self._get_total_sec()

    def _get_videos(self):
        if os.path.isdir(self.path):
            for root, dirs, files in os.walk(self.path):
                for file in files:
                    if os.path.splitext(file)[1] in self.format_list:
                        path = os.path.join(root, file)
                        yield path
        else:
            yield self.path

    def _get_total_sec(self):
        total_secondes = 0
        for file_path in self._get_videos():
            try:
                cap = cv2.VideoCapture(file_path)
                rate = cap.get(5)
                frame_number = cap.get(7)
                duration = frame_number / rate
                total_secondes += duration
            except Exception:
                print(traceback.format_exc(limit=2))
        return total_secondes

    @staticmethod
    def format_print(sec):
        hours = sec // 3600
        minutes = (sec % 3600) // 60
        secondes = ((sec % 3600) % 60)
        return '{:.0f}小时{:.0f}分钟{:.0f}秒'.format(hours, minutes, secondes)


if __name__ == '__main__':
    path = sys.argv[1]
    vp = VideoPlan(path)
    vp_1x = vp.format_print(vp.total_secondes)
    vp_2x = vp.format_print(vp.total_secondes / 2)
    print('1倍速播放需{}\n2倍速播放需{}'.format(vp_1x, vp_2x))
    input('any to quit')